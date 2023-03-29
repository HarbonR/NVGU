{
program part1_z13;

const
  n = 3; // Объявляем константу для двухмерного массива

begin // Тело программы
  var i, j, s0, s1: Integer; // Объявляем переменные типа Integer
  var bol: Boolean; // Объявляем переменную типа Boolean
  bol := true; // Присваиваем значение true переменной bol
  var mas: array [1..n, 1..n] of Integer; // Объявляем переменную типа: 2 мерный массив
  writeln('Введите матрицу ', n, '*', n); // Вывод сообщения в консоль 
  for i := 1 to n do // Цикл с вложенным циклом для 2 мерного массива
    for j := 1 to n do // Вложенный цикл
      read(mas[i, j]); // Запрашивает ввод матрицы с n*n
  for j := 1 to n do // Цикл считает сумму первой строки (А11,А12,А1n...)
    s0 := s0 + mas[1, j]; // Строчка А1 J меняется от 1 до n
  for i := 1 to n do // Цикл с вложенными циклами
  begin // Тело цикла
    s1 := 0; // Обнуляет переменную s1
    for j := 1 to n do // Цикл считает сумму строк (А11,А12,А1n...)
      s1 := s1 + mas[i, j]; //       по отдельности (Аn1,An2,Ann...)
    if s0 <> s1 then // Сравнивает сумму первой строки и всех последующих строк
      bol := false; // Если суммы не равны то присваивает переменной bol - false
    s1 := 0; // Обнуляет переменную s1
    for j := 1 to n do // Цикл считает сумму столбцов (А11,А12,А1n...)
      s1 := s1 + mas[j, i]; //          по отдельности (Аn1,An2,Ann...)
    if s0 <> s1 then // Сравнивает сумму первой строки и всех последующих столбцов
      bol := false; // Если суммы не равны то присваивает переменной bol - false
  end;
  if bol then // Если переменная bol осталась true, то выполняется следующий код
    writeln('Матрица - магический квадрат') // Вывод сообщения в консоль 
  else // Иначе
    writeln('Матрица не является магическим квадратом'); // Вывод сообщения в консоль 
end.
}
{
program part1_z23;

const
  m = 3; // Количество строк

const
  n = 3; // Количество столбцов

var
  i, j, k, c, d: Integer;

var
  mas: array[1..m, 1..n] of Integer; // Основная матрицы

var
  numberString: array[1..m] of Integer; // Матрица № строк, где есть хоть 1 с

begin
  writeln('Введите матрицу ', m, '*', n); // Вывод сообщения в консоль
  for i := 1 to m do // Цикл с вложенным циклом для 2 мерного массива
    for j := 1 to n do // Вложенный цикл
      read(mas[i, j]); // Запрашивает ввод матрицы с m*n
  write('Введите c = '); read(c); // Вывод сообщения в консоль и запрос ввода
  write('Введите d = '); read(d); // Вывод сообщения в консоль и запрос ввода
  for i := 1 to m do // Цикл с вложенным циклом для 2 мерного массива
    for j := 1 to n do // Вложенный цикл
    begin
      if mas[i, j] = c then // Если в строке матрицы встречается с то в матрицу № строк
      begin
        numberString[i] := numberString[i] + i; // записывается номер строки
        break; // Выход из вложенного цикла
      end;
    end;
  writeln('Номера строк матрицы, где хотя бы один элемент равен с = ', numberString);
  for i := 1 to m do // Цикл проходит по строкам (А11..А1n)
  begin                                        //(A21..A2n)
    c := numberString[i]; // с присваивается № строки основной матрицы где есть с  
    if c <> 0 then // если с не равно 0, то элементы строки где есть с, умножаются на d
      for j := c to c do
        for k := 1 to n do
          mas[c, k] := mas[c, k] * d;
  end;
  for i := 1 to m do // Цикл выводит в консоль изменённую матрицу
  begin
    for j := 1 to n do
      write(mas[i, j]:3);
    writeln;
  end;
end.
}
{
program part2_z13;

const
  n = 2;

type
  masMN = array[1..n, 1..n] of integer; // Создаётся новый тип данных (2 мерный массив)

function randMas(var mas: masMN): masMN; // Функция рандомно заполняет 2 мерный массив
var
  i, j: Integer;
begin
  for i := 1 to n do
    for j := 1 to n do
      mas[i, j] := random(1, 5);
  randMas := mas;
end;

procedure wrMas(mas: masMN); // Процедура выводит в консоль 2 мерный массив
var
  i, j: Integer;
begin
  for i := 1 to n do
  begin
    for j := 1 to n do
      write(mas[i, j]:3);
    writeln;
  end;
end;

function plusMas(A: masMN; B: masMN): masMN; // Функция складывает две матрицы
var
  i, j: Integer;
var
  summ: masMN;
begin
  for i := 1 to n do
    for j := 1 to n do
      summ[i, j] := A[i, j] + B[i, j];
  plusMas := summ;
end;

function multiplyMas(A: masMN; B: masMN): masMN; // Функция умножает две матрицы
var
  i, j, k: Integer;
var
  summ: masMN;
begin
  for i := 1 to n do
    for j := 1 to n do
      for k := 1 to n do
        summ[i, j] :=  summ[i, j] + A[i, k] * B[k, j];
  multiplyMas := summ;
end;

begin
  var A: masMN;
  var B: masMN;
  var C: masMN;
  writeln('Матрица А'); wrMas(randMas(A));
  writeln('Матрица B'); wrMas(randMas(B));
  writeln('Матрица C'); wrMas(randMas(C));
  writeln('Матрица (A + B)*C'); wrMas(multiplyMas(plusMas(A, B), C));
end.
}
{
program part2_z4;

const
  n = 2;

type
  masN = array[1..n, 1..n] of Real; // Создаётся новый тип данных (2 мерный массив)

function randMas(var mas: masN): masN; // Функция рандомно заполняет 2 мерный массив
var
  i, j: Integer;
begin
  for i := 1 to n do
    for j := 1 to n do
      mas[i, j] := random(1, 5);
  randMas := mas;
end;

procedure wrMas(mas: masN); // Процедура выводит в консоль 2 мерный массив
var
  i, j: Integer;
begin
  for i := 1 to n do
  begin
    for j := 1 to n do
      write(mas[i, j]:5:1);
    writeln;
  end;
end;

function formMas(mas: masN): masN; // Функция вычисляет элементы матрицы по формуле
var
  i, j: Integer;
var
  masB: masN;
begin
  for i := 1 to n do
    for j := 1 to n do
      masB[i, j] := 1 / (i + j - 1);
  formMas := masB;
end;

function multiplyMas(A: masN; B: masN): masN; // Функция умножает две матрицы
var
  i, j, k: Integer;
var
  summ: masN;
begin
  for i := 1 to n do
    for j := 1 to n do
      for k := 1 to n do
        summ[i, j] :=  summ[i, j] + A[i, k] * B[k, j];
  multiplyMas := summ;
end;

begin
  var A: masN;
  var B: masN;
  writeln('Матрица А'); wrMas(randMas(A));
  writeln('Матрица B'); wrMas(formMas(B));
  writeln('Матрица A*B'); wrMas(multiplyMas(A, formMas(B)));
end.
}