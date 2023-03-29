{
program part1Z_13;

const
  n: Integer = 10; // Обявляем константу для количества элементов массива

begin
  var i: Integer;
  var myArray: array [1..n] of Integer; // Пустой массив на n элементов с типом Integer
  for i := 1 to n do // Цикл заполняет массив рандомными числами
    myArray[i] := random(10);
  writeln('Рандомный массив  = ', myArray);
  for i := 1 to n do // Цикл изменяет числа в рандомном массиве [i] < 2 = 0
    if myArray[i] < 2 then 
      myArray[i] := 0;
  write('Изменённый массив = ', myArray);
end.
}
{
program part1Z_23;

const
  n: Integer = 10; // Обявляем константу для количества элементов массива

begin
  var i, min, max: Integer;
  var myArray: array [1..n] of Integer; // Пустой массив на n элементов с типом Integer
  for i := 1 to n do // Цикл заполняет массив рандомными числами
    myArray[i] := random(10,100);
  writeln('Массив рандомных чисел = ', myArray);
  min := myArray[2];
  writeln('min[2] = ', min);
  max := myArray[1];
  writeln('max[1] = ',max);
  for i := 1 to n do
  begin
    if i mod 2 <> 0 then
      begin
      if max <= myArray[i] then
      max := myArray[i]
      end
    else if i mod 2 = 0 then
      begin
      if min >= myArray[i] then
      min := myArray[i]
      end
  end;
  writeln('Min четное i = ', min);
  writeln('Max нечетное i = ', max);
  writeln('Сумма min и max = ', min + max)
end.
}
{
program part2Z_13;

const
  n: Integer = 10; // Обявляем константу для количества элементов массива

begin
  var i, uneven: Integer;
  var myArray: array [1..n] of Integer; // Пустой массив на n элементов с типом Integer
  for i := 1 to n do // Цикл заполняет массив рандомными числами
    myArray[i] := random(1, 10);
  writeln('Массив рандомных чисел = ', myArray);
  uneven := 1;
  write('Элементы массива имеющих нечетные индексы = ', uneven);
  for i := 1 to n do
  begin
    if i mod 2 <> 0 then
    begin
      write(' * ', myArray[i]);
      uneven := uneven * myArray[i];
    end
  end;
  writeln();
  write('Произведение = ', uneven);
end.
}
{
program part2Z_23;

const
  n: Integer = 10; // Обявляем константу для количества элементов массива

begin
  var i, min: Integer;
  var myArray: array [1..n] of Integer; // Пустой массив на n элементов с типом Integer
  for i := 1 to n do // Цикл заполняет массив рандомными числами
    myArray[i] := random(1,10);
  writeln('Рандомный массив  = ', myArray);
  min := myArray[1];
  for i := 1 to n do
    begin
    if min >= myArray[i] then
      min := myArray[i];
    end;
  writeln('Минимальное число = ', min);
  myArray[1] := min;
  writeln('Измененный массив = ', myArray);  
end.
}