{
program z13;
uses graphABC; 
var radius : Integer;
begin
  radius := 50;
  rectangle(70,70,450,370); // Рисует прямоугольник
  circle(150,225,radius); // Рисует круг
  circle(225,225,radius); // Рисует круг
  circle(300,225,radius); // Рисует круг
  circle(375,225,radius); // Рисует круг
  arc(150,225,radius,40,-40); // Рисует дугу
  arc(225,225,radius,40,-40); // Рисует дугу
  arc(300,225,radius,40,-40); // Рисует дугу
  floodFill(150,225, clyellow); // Выполняет заливку 1 круга
  floodFill(225,225, clSkyBlue); // Выполняет заливку 2 круга
  floodFill(300,225, clRed); // Выполняет заливку 3 круга
  floodFill(375,225, clFuchsia); // Выполняет заливку 4 круга
  floodFill(190,225, clOlive); // Выполняет заливку между 1 и 2 кругом
  floodFill(265,225, clPink); // Выполняет заливку между 2 и 3 кругом
  floodFill(340,225, clMoneyGreen); // Выполняет заливку между 3 и 4 кругом
end.
}
{
program z13;
uses graphABC;
procedure k1 ();
begin
  moveTo(110,140);
  lineTo(110,110);
  moveTo(110,125); // Середина буквы
  lineTo(130,110);
  moveTo(110,125);
  lineTo(130,140);
end;
procedure o1();
begin
  circle(145,130,10);
end;
procedure v();
begin
  moveTo(165,140);
  lineTo(165,120);
  arc(165,125,5,90,-90);
  arc(165,135,5,90,-90);
end;
procedure a();
begin
  moveTo(180,140);
  lineTo(185,120);
  lineTo(190,140);
  moveTo(182,136);
  lineTo(188,136);
end;
procedure l();
begin
  moveTo(200,140);
  lineTo(205,120);
  lineTo(210,140);
end;
procedure e();
begin
  moveTo(220,140);
  lineTo(220,120);
  lineTo(230,120);
  moveTo(220,140);
  lineTo(230,140);
  moveTo(220,130); // Середина буквы
  lineTo(230,130);
end;
procedure n();
begin
  moveTo(240,140);
  lineTo(240,120); // |1
  moveTo(240,130);
  lineTo(250,130);
  moveTo(250,140);
  lineTo(250,120);
end;
procedure k2();
begin
  moveTo(260,140);
  lineTo(260,120);
  moveTo(260,130); // Середина
  lineTo(270,120);
  moveTo(260,130); // Середина
  lineTo(270,140);
end;
procedure o2();
begin
  circle(285,130,10);
end;
begin
  rectangle(100,100,500,150);
  k1();
  o1();
  v();
  a();
  l();
  e();
  n();
  k2();
  o2();
end.
}