{
program z13;
uses MyUnit;
var a,b,c: Real;
begin
  a := 3;
  b := 4;
  c := 3;
  Perimeter(a,b,c);
  Area(a,b,c);
end.
}
{
program z4;
uses MyUnit;
var a,b : Integer;
begin
  a := 8;
  b := 13;
  writeln('Наибольший общий делитель = ', nod(a,b));
  writeln('Наименьшее общее кратное = ',nok(a,b));
end.
}