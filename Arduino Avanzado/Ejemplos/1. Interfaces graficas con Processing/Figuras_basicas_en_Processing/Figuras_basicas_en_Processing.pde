// Creamos nuestro 'lienzo'
size(500,200);
// Para determinar el color del lienzo; 0 corresponde a negro y 255 a blanco
background(0);

// Rectángulo o cuadrado:  rect(cordenada x, cordenada y, largo, ancho);
rect(250,100,100,50);

// Círculo: ellipse(coordenada x, coordenada y, largo, ancho);
ellipse(250,100,100,50);

// Triángulo: triangle(x1,y1,x2,y2,x3,y3);
triangle(100,100,250,100,150,50);

background(255);

// Punto:  point(coordenada x, coordenada y);
point(200,100);

// Línea:  line(x1,y1,x2,y2);
line(0,0,500,200);
