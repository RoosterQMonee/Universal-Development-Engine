# Universal Development Engine

**Note** : i probably wont work on this much. wouldn't recommend using it for anything more than a project.

## Platorms

* Windows 8/8.1/10 - temporarily broken on 11

## General Features

* 2D Windows

> * Buttons
> * Check Boxes
> * Combo Boxes
> * List Boxes
> * Text Boxes
> * Labels

* 3D rendering

> * Cameras
> * Lights
> * Models
> * Objects

* Basic Neural Networks

> * Included MSINT dataset ( Trained / Raw set )


# Documentation

### Installation

* Download .ZIP file or clone repository

* Move folder to `C:\Users\USERNAME\AppData\Local\Programs\Python\Python310\Lib\site-packages` or root folder for your program

* Import by using `import UDE`


### Modules

#### UDE Windows

* This is in the base module ( just UDE )

Main window: `UDE.window(Width, Height`

Use `init` with your window to load its properties ( Must be before other items )

All have the same class arguments: `(x <DEFAULT=0>, y <DEFAULT=0>, width <DEFAULT=10>, height <DEFAULT=10>)`

> * UDE.Button
> * UDE.CheckBox
> * UDE.ComboBox
> * UDE.ListBox
> * UDE.TextBox
> * UDE.Label

Use the `render()` function to initialize the item

* Button
> * Parent, Text

* CheckBox
> * Parent, Text

* ComboBox
> * Parent

* Label
> * Parent, Text

* ListBox
> * Parent

* TextBox
> * Parent


Use the `update()` function with your window to update and load it ( Required )

```
import UDE

window = UDE.window(300, 300)
window.init(b"Window")

while True:
  window.update()
  UDE.time.sleep(100)
```

#### UDE Engine

* This is in UDE.Engine

* Camera(self, position, near, far, fov)

* Scene(self, world=[])

* Vector3(self, x=0, y=0, z=0)

* Vector2(self, x=0, y=0)

* toVector3(matrix)

* crossProduct(a, b)

