# 3d-shrine-game

A Japanese style shrine/temple. A man is placing a coin into the box in the temple.

<img src="https://github.com/alex-bull/3d-shrine-game/blob/master/outside.png?raw=true" width="500"><img src="https://github.com/alex-bull/3d-shrine-game/blob/master/inside.png?raw=true" width="500">

Controls: Left and right keys to adjust left and right camera angle. Up and down keys to move
camera forwards and back. F1 key to toggle between controllable camera and the humans POV
camera.

There is a sky box. The temple is constructed entirely out of vertex definitions and GLUT objects.
The spinning top is an example of a surface of revolution generated object. The teapot display is an
example of a model made from three GLUT objects. There is a human who walks into the temple,
deposits a coin, and leaves again. This is on loop. There is a light source in the sky outside and
a spotlight shining from the roof down onto the teapot/GLUT display. The teapot and torus have
specular reflections. The roof, flooring, money box, and lucky cat use texturing. The camera is
able to be moved using the keyboard.

Five models: the human, the spinning top, the teapot/GLUT display, the offerings box with coin
included, and the lucky cat.

Extra features implemented: a spotlight above a moving object(s)/the teapot/GLUT display, planar
shadows coming from the entrance archway, and multiple camera views (accessed by the F1 key).
