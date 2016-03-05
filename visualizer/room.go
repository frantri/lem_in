package main

import (
	"strconv"
	"github.com/veandco/go-sdl2/sdl"
)

type Room struct {
	Name		string
	X, Y		int64
	Ants		uint
	Ant			bool
	Neighbours	[]*Room
	Surface		*sdl.Rect
}

func NewRoom(name string, x, y int64, ants uint, ant bool) *Room {
	return &Room{name, x, y,ants, ant, nil, nil}
}

func (r *Room) AddNeighbour(ngh *Room) {
	r.Neighbours = append(r.Neighbours, ngh)
}

func (r *Room) RemoveNeighbour(ngh *Room) {
	i := 0
	for i < len(r.Neighbours) {
		i++
	}
	r.Neighbours[i] = r.Neighbours[len(r.Neighbours)-1]
	r.Neighbours[len(r.Neighbours)-1] = nil
	r.Neighbours = r.Neighbours[:len(r.Neighbours)-1]
}

func (r *Room) String() string {
	var res string
	res = "ROOM:" + r.Name + ", ant:" +
	strconv.FormatBool(r.Ant) + ", ants:" +
	strconv.FormatUint(uint64(r.Ants), 10) +
	", coords:(" +  strconv.FormatInt(r.X, 10) + "," +
	strconv.FormatInt(r.Y, 10) + ") Neighbours: "
	for i := 0; i < len(r.Neighbours); i++ {
		res += r.Neighbours[i].Name + ", "
	}
	return res
}
