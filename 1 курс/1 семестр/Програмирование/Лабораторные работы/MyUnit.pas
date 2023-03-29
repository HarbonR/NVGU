/// Модуль с процедурами и функциями:
/// 1.Perimeter
/// 2.Area
/// 3.Nod
/// 4.Nok
unit MyUnit;
interface
procedure Perimeter (a: Real; b: Real; c: Real);
procedure Area (a: Real; b: Real; c: Real);
function Nod (x,y:longint):longint;
function Nok(x,y:longint):longint;
implementation
///Процедура считает периметр треугольника по 3 сторонам
procedure Perimeter;
var p : Real;
begin
  p := a + b + c;
  writeln('Периметр треуголтника = ', p);
end;
///Процедура считает площадь треугольника по 3 сторонам
procedure Area;
var p, s : Real;
begin
  p := (a + b + c)/2;
  s := sqrt(p*(p-a)*(p-b)*(p-c));
  writeln('Площадь треуголтника = ', s);
end;
/// Функция ищет наибольший общий делитель
function Nod (x,y:longint):longint; 
begin
   if x<>0 then Nod:=Nod(y mod x,x) else Nod:=y;
end;
/// Функция ищет наименьшее общее кратное
function Nok(x,y:longint):longint;
begin
   Nok:=( x div Nod(x,y) ) * y;
end;
begin
  
end.