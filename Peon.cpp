
void Peon::setcolor(bool _color)
{
	color = _color;
}

void Peon::dibuja()
{

	if (color)
		spritep = { "bin/imagenes/peon_negras.png", pos.x + 0.57f, pos.y - 0.1f, 11, 3.5 };
	else
		spritep = { "bin/imagenes/peon_blancas.png", pos.x + 0.67f, pos.y - 0.23f, 11, 3.5 };

	glPushMatrix();
	glTranslatef(0, 0, 0.002);
	spritep.draw();
	glPopMatrix();
}
