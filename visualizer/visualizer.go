package main

import (
	"bufio"
	"errors"
	"fmt"
	"github.com/veandco/go-sdl2/sdl"
	"os"
	"strconv"
	"strings"
	"time"
)

var winTitle string = "Lem_in_visualizer"
var winWidth, winHeight int = 1600, 900

func handleSharpLine(m *Map, b []byte) int {
	var s string = string(b)
	if len(b) < 2 || b[1] != '#' {
		return 0
	}
	if s == "##start" {
		return 1
	} else if s == "##end" {
		return 2
	}
	return 0
}

func printMap(m *Map, renderer *sdl.Renderer) {
	renderer.SetDrawColor(0, 0, 0, 255)
	renderer.Clear()
	for _, r := range m.Rooms {
		for _, ngh := range r.Neighbours {
			renderer.SetDrawColor(255, 255, 255, 255)
			renderer.DrawLine(int(r.X), int(r.Y), int(ngh.X), int(ngh.Y))
			renderer.DrawLine(int(r.X), int(r.Y+1), int(ngh.X), int(ngh.Y+1))
			renderer.DrawLine(int(r.X+1), int(r.Y), int(ngh.X+1), int(ngh.Y))
		}
	}
	for _, r := range m.Rooms {
		if r.Ants != 0 {
			renderer.Copy(m.Texture, nil, r.Surface)
		} else {
			if r == m.End {
				renderer.SetDrawColor(0, 255, 0, 255)
			} else if r == m.Start {
				renderer.SetDrawColor(0, 0, 255, 255)
			} else {
				renderer.SetDrawColor(255, 0, 0, 255)
			}
			renderer.FillRect(&sdl.Rect{int32(r.X - 10), int32(r.Y - 10), 20, 20})
		}
	}
}

func printNormalMap(m *Map, renderer *sdl.Renderer) {
	renderer.SetDrawColor(0, 0, 0, 255)
	renderer.Clear()
	for _, r := range m.Rooms {
		for _, ngh := range r.Neighbours {
			renderer.SetDrawColor(255, 255, 255, 255)
			renderer.DrawLine(int(r.X), int(r.Y), int(ngh.X), int(ngh.Y))
			renderer.DrawLine(int(r.X), int(r.Y+1), int(ngh.X), int(ngh.Y+1))
			renderer.DrawLine(int(r.X+1), int(r.Y), int(ngh.X+1), int(ngh.Y))
		}
	}
	for _, r := range m.Rooms {
		if r == m.End {
			renderer.SetDrawColor(0, 255, 0, 255)
		} else if r == m.Start {
			renderer.SetDrawColor(0, 0, 255, 255)
		} else {
			renderer.SetDrawColor(255, 0, 0, 255)
		}
		renderer.FillRect(&sdl.Rect{int32(r.X - 10), int32(r.Y - 10), 20, 20})
	}
}

func readMap(reader *bufio.Reader) (*Map, error) {
	var m *Map = new(Map)
	var line string
	var err error
	var flag int

	if line, err = reader.ReadString('\n'); err != nil {
		os.Exit(1)
	}
	line = strings.Replace(line, "\n", "", 1)
	x, er := strconv.Atoi(line)
	if er != nil {
		return nil, er
	}
	m.Ants = uint(x)
	for line, err = reader.ReadString('\n'); line != "\n"; line, err = reader.ReadString('\n') {
		if err != nil {
			return nil, err
		}
		line = strings.Replace(line, "\n", "", 1)
		var b []byte = []byte(line)
		if b[0] == '#' {
			flag = handleSharpLine(m, b)
		} else if strings.Count(line, " ") > 2 {
			return nil, errors.New("Invalid line")
		} else if strings.Count(line, " ") == 2 {
			split := strings.Split(line, " ")
			x, er := strconv.Atoi(split[1])
			if er != nil {
				return nil, er
			}
			y, er := strconv.Atoi(split[2])
			if er != nil {
				return nil, er
			}
			var r *Room = NewRoom(split[0], int64(x), int64(y), 0, false)
			if flag == 1 {
				m.Start = r
			} else if flag == 2 {
				m.End = r
			}
			m.AddRoom(r)
			flag = 0
		} else {
			split := strings.Split(line, "-")
			if m.SetNeighbour(split[0], split[1]) == false {
				return nil, errors.New("Invalid roon link")
			}
		}
	}
	return m, nil
}

func ModifyCoords(m *Map) {
	x_ratio, y_ratio := int64(1000000), int64(100000)
	for _, r := range m.Rooms {
		if x_ratio > int64(winWidth)/(r.X+1) {
			x_ratio = int64(winWidth) / (r.X + 1)
		}
		if y_ratio > int64(winHeight)/(r.Y+1) {
			y_ratio = int64(winHeight) / (r.Y + 1)
		}
	}
	for _, r := range m.Rooms {
		r.X = r.X * (x_ratio - 1)
		r.Y = r.Y * (y_ratio - 1)
		r.Surface = &sdl.Rect{int32(r.X - 25), int32(r.Y - 25), 50, 50}
	}
}

func HandleMvt(renderer *sdl.Renderer, m *Map, mvt string, c chan *sdl.Rect) error {
	var b []byte = []byte(mvt)
	var src, dest *Room
	var rect *sdl.Rect
	var err error

	b = b[1:len(b)]
	split := strings.Split(string(b), "-")
	ant, _ := strconv.Atoi(split[0])
	room_name := split[1]
	src, err = m.GetRoomFromAnt(uint(ant))
	if err != nil {
		os.Exit(1)
	}
	dest, err = m.GetRoomFromName(room_name)
	if err != nil {
		os.Exit(1)
	}
	for i := int32(1); i < 6; i++ {
		dx := int32(src.X - dest.X)
		dy := int32(src.Y - dest.Y)
		rect = &sdl.Rect{int32(src.X) - (i*dx)/5 - 25,
			int32(src.Y) - (i*dy)/5 - 25, 50, 50}
		c <- rect
	}
	if dest != m.End {
		dest.Ants = uint(ant)
	}
	if src == m.Start && m.Start.Ants > 0 {
		src.Ants--
	}
	close(c)
	return nil
}

func playTurn(reader *bufio.Reader, m *Map, renderer *sdl.Renderer) {
	var line string
	var err error

	if m.Ants == m.End.Ants {
		return
	}
	line, err = reader.ReadString('\n')
	if err != nil {
		return
	}
	if line != "" {
		line = strings.Replace(line, "\n", "", 1)
		moves := strings.Fields(line)
		chans := make([]chan *sdl.Rect, len(moves))
		for i := 0; i < len(chans); i++ {
			chans[i] = make(chan *sdl.Rect, 1)
		}
		for i, s := range moves {
			go HandleMvt(renderer, m, s, chans[i])
		}
		for i := 0; i < 5; i++ {
			printNormalMap(m, renderer)
			renderer.SetDrawColor(0, 255, 0, 255)
			for _, c := range chans {
				r := <-c
				renderer.Copy(m.Texture, nil, r)
			}
			renderer.Present()
			time.Sleep(400 * time.Millisecond)
		}
		setAnts(m, line)
		printMap(m, renderer)
		renderer.Present()
		setAnts(m, line)
	}
}

func contains(rooms []*Room, r *Room) bool {
	for _, room := range rooms {
		if r == room {
			return true
		}
	}
	return false
}

func setAnts(m *Map, line string) {
	split := strings.Fields(line)
	var rooms []*Room
	for _, mvt := range split {
		s := strings.Split(mvt, "-")
		r, _ := m.GetRoomFromName(s[1])
		rooms = append(rooms, r)
	}
	for _, room := range m.Rooms {
		if contains(rooms, room) == false {
			room.Ants = 0
		}
	}
}

func main() {

	var m *Map
	reader := bufio.NewReader(os.Stdin)
	var window *sdl.Window
	var renderer *sdl.Renderer
	var event sdl.Event
	var running bool
	var err error
	var image *sdl.Surface
	var texture *sdl.Texture

	m, err = readMap(reader)
	if err != nil {
		fmt.Println("Erreur")
		os.Exit(1)
	}

	ModifyCoords(m)

	window, err = sdl.CreateWindow(winTitle, sdl.WINDOWPOS_UNDEFINED,
		sdl.WINDOWPOS_UNDEFINED, winWidth, winHeight, sdl.WINDOW_SHOWN)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Failed to create window %s\n", err)
		return
	}
	defer window.Destroy()

	renderer, err = sdl.CreateRenderer(window, -1, sdl.RENDERER_ACCELERATED)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Failed to create renderer %s\n", err)
		return
	}
	defer renderer.Destroy()

	image, err = sdl.LoadBMP("./assets/ant.bmp")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Failed to load BMP: %s\n", err)
		return
	}
	defer image.Free()

	texture, err = renderer.CreateTextureFromSurface(image)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Failed to create texture: %s\n", err)
		return
	}
	defer texture.Destroy()

	m.Texture = texture
	printMap(m, renderer)

	renderer.Present()

	running = true

	for running {
		for event = sdl.PollEvent(); event != nil; event = sdl.PollEvent() {
			switch event.(type) {
			case *sdl.QuitEvent:
				running = false
			case *sdl.KeyDownEvent:
				touche := sdl.GetKeyName(event.(*sdl.KeyDownEvent).Keysym.Sym)
				if touche == "Escape" {
					running = false
				} else if touche == "Space" {
					playTurn(reader, m, renderer)
				}
			}
		}
	}
}
