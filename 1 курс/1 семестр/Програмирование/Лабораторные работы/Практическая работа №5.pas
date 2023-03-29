procedure screen(nameProgramm, author: String; str1: String := 'Программа');
var
  i, n, lengthStr: Integer; // Обявление переменных с типом Integer
var
  signStr, spaceStr: String; // Обявление переменных с типом String
begin
  n := 1;
  signStr := ''; // строка cимволы
  spaceStr := ''; // строка пробелы 
  if length(nameProgramm) > length(author) then // Проверка. Какая строка длиньше
    lengthStr := length(nameProgramm)
  else if length(nameProgramm) < length(author) then
    lengthStr := length(author);
  lengthStr := lengthStr + 6; // Длина всей строки + 6 
  for i := 1 to lengthStr do // Цикл с счетчиком от 1 до длинны строки + 6
  begin
    signStr := signStr + '*'; // Циклично прибовляет к переменной "строка cимволы" символ
    spaceStr := spaceStr + '-'; // Циклично прибовляет к переменной "строка пробелы" пробел
  end;
  while length(str1) < lengthStr - 2 do // По аналогии с nameProgramm
  begin
    if n = 0 then
      str1 := str1 + ' '
    else if n = 1 then
      str1 := ' ' + str1;
    n := (n + 1) mod 2
  end;
  while length(nameProgramm) < lengthStr - 2 do // Пока длинна строки nameProgramm < lengthStr - 2 будет выполнятся следующий код
  begin
    if n = 0 then
      nameProgramm := nameProgramm + ' ' // Если n = 1 то спереди к nameProgramm будет добавляться пробел
    else if n = 1 then
      nameProgramm := ' ' + nameProgramm; // Если n = 0 то сзади к nameProgramm будет добавляться пробел
    n := (n + 1) mod 2 // Циклично будет находиться остаток от деления на 2. 2%2=0; 1%2=0,5=1 т.к. mod работает только с типом int. Происходит округление.
  end;
  while length(author) < lengthStr - 2 do // По аналогии с nameProgramm
  begin
    if n = 0 then
      author := author + ' '
    else if n = 1 then
      author := ' ' + author;
    n := (n + 1) mod 2
  end;
  writeln(signStr); // Вывод в консоль: строка cимволы
  writeln(spaceStr); // Вывод вконсоль: строка пробелы 
  writeln('*' + str1 + '*');
  writeln(spaceStr); // Вывод вконсоль: строка пробелы 
  writeln('*' + nameProgramm + '*');
  writeln(spaceStr); // Вывод вконсоль: строка пробелы 
  writeln('*' + author + '*');
  writeln(spaceStr); // Вывод вконсоль: строка пробелы 
  write(signStr); // Вывод в консоль: строка cимволы
end;
{
// Задание 13

const
  n = 10;

var
  i, j: Integer;

function FullSqr(A: Longint): Boolean;
begin
  if A - Sqr(Round(Sqrt(A))) = 0 then FullSqr := True else FullSqr := False;
end;

begin
  screen('Задание 13','Автор: Коваленко П.И.');
  writeln();
  for i := 2 to n - 1 do
    for j := 1 to i - 1 do
      if FullSqr(j) and FullSqr(i - j) then
        writeln(i, ' = ', j, '+', i - j, ' = ', Round(Sqrt(j)), '^2+', Round(Sqrt(i - j)), '^2');
end.
}
{
// Задание 18
procedure digit ();
begin
var
  i, summ: integer;
for i := 100 to 999 do
    if ((i mod 10) mod 2 <> 0) and (((i div 10) mod 10) mod 2 <> 0) and
    ((i div 100) mod 2 <> 0) then
    begin
      write(i + ' ');
      summ := summ + i
    end;
  writeln();
  write('Cумма = ', summ);
end;
begin
  screen('Задание 18','Автор: Коваленко П.И.');
  writeln();
  digit();
end.
}
{
//Задание 1

function f(a, b, c: real): real;
begin
  f := (2 * a - b - sin(c)) / 5 + abs(c);
end;

var
  s, t, x: real;

begin
  screen('Задание 1','Автор: Коваленко П.И.');
  writeln();
  write('Введите s = '); readln(s);
  write('Введите t = '); readln(t);
  x := f(t, -2 * s, 1.17) + f(2.2, t, s - t);
  write('X = ', x:0:3)
end.
}