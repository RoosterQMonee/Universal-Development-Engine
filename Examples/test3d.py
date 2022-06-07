import sys
import pygame
from pygame.locals import *
from UDE import *
from random import randint

pygame.init()

flags = DOUBLEBUF
screen = pygame.display.set_mode(Engine.Size, flags, 16)
clock = pygame.time.Clock()
fps = 15

pygame.mouse.get_rel()
pygame.mouse.set_visible(True)
a = pygame.event.set_grab(False)

res = 1
scene = Engine.Scene()

for x in range(res):
    for y in range(res):
        for z in range(res):
            cube = Engine.Mesh()
            s = 5

            r = randint(10, 255)
            g = randint(10, 255)
            b = randint(10, 255)

            cube.triangles = Engine.CubeTriangles((r, g, b),Engine.Vector3(x * s, y * s, z * s), s)
            cube.position = Engine.Vector3(x * s, y * s, z * s)
            cube.transform = Engine.Matrix.scaling(0.1)

            scene.world.append(cube)

camera = Engine.Camera(Engine.Vector3(0, 0, 0), 0.1, 1000.0, 75.0)
camera.speed = 1
camera.rotationSpeed = 0.8

light = Engine.Light(Engine.Vector3(0.9, 0.9, -1))
hue = 0

angle = 0
moveLight = True
run = True

while run:
    screen.fill(Engine.BackgroundColor)
    clock.tick(fps)
    dt = clock.tick(fps)/100
    frameRate = clock.get_fps()

    run = Engine.HandleEvent(camera, dt)
    hue = 0

    camera.HandleInput(dt)

    if moveLight == True and light != None:
        mx, my = pygame.mouse.get_pos()

        _x = Engine.translateValue( mx, 0,  Engine.Width,  -1,  1)
        _y = Engine.translateValue( my, 0, Engine.Height, -1, 1)

        light = Engine.Light(Engine.Vector3(-_x, -_y, -1))

    scene.update(
        dt = dt,
        camera=camera,
        light=light,
        screen=screen,
        showAxis=False,
        fill=True,
        wireframe=False,
        vertices=False,
        depth=False,
        clippingDebug=False,
        showNormals=False,
        radius=2,
        verticeColor=False,
        wireframeColor=(255, 255, 255),
        ChangingColor=hue)

    pygame.display.flip()
    angle += 0.01

pygame.quit()
sys.exit()
