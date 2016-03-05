package main

import (
	"errors"
	"github.com/veandco/go-sdl2/sdl"
)

type Map struct {
	Rooms []*Room
	Ants  uint
	Start *Room
	End   *Room
	Texture *sdl.Texture
}

func NewMap(rooms []*Room, ants uint, start, end *Room) *Map {
	return &Map{rooms, ants, start, end, nil}
}

func (m *Map) SetNeighbour(s1, s2 string) bool {
	var r1, r2 *Room
	for i := 0; i < len(m.Rooms); i++ {
		if m.Rooms[i].Name == s1 {
			r1 = m.Rooms[i]
		}
		if m.Rooms[i].Name == s2 {
			r2 = m.Rooms[i]
		}
	}
	if r1 == nil || r2 == nil {
		return false
	}
	r1.AddNeighbour(r2)
	r2.AddNeighbour(r1)
	return true
}

func (m *Map) AddRoom(r *Room) {
	m.Rooms = append(m.Rooms, r)
}

func (m *Map) GetRoomFromAnt(ant uint) (*Room, error) {
	for _, r := range m.Rooms {
		if r.Ants == ant {
			return r, nil
		}
	}
	return m.Start, nil
}

func (m *Map) GetRoomFromName(name string) (*Room, error) {
	for _, r := range m.Rooms {
		if r.Name == name {
			return r, nil
		}
	}
	return nil, errors.New("Invalid name")
}
