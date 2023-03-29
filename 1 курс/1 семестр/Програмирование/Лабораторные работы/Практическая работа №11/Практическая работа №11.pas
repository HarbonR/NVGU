{
program part1_z13;

var i, counter : Integer;
var str, variableStr : String;
var fail : text;

begin 
  assign(fail, 'Input.txt'); // Связывает переменную файлового типа с внешним файлом
  reset(fail); // Открывает фаил
  read(fail, str); // Считывает из файла данные и записывает в переменную str
  for i := 1 to length(str) do
    if str[i] = ' ' then
      begin
      if variableStr[1] = variableStr[length(variableStr)] then // Первый и последний символ
        counter := counter + 1; // Выполняется инкремент
      variableStr := ''; // Переменная сбрасывает значения
      end
    else 
      variableStr := variableStr + str[i]; // В переменную по буквам записываются слово
   close(fail); // Фаил сохраняется и закрывается
   write('Количество слов: ', counter); // Вывод результата в консоль
end.
}
{
program part1_z5;

var str, сhangeStr : String;
var i : Integer;
var fail1, fail2 : text;
begin
assign(fail1, 'Input.txt'); // Связывает переменную типа файл с файлом 
assign(fail2, 'Ouput.txt');
reset(fail1); // Открывает файл
rewrite(fail2); // Открывает файл
read(fail1, str); // Считывает из файла данные и записывает в переменную str
for i:=1 to length(str) do
  сhangeStr := сhangeStr + (Upcase(str[i])); // Функция Upcase() переводит буквы в верхний регистр
write(fail2, сhangeStr); // В файл записывается строка сhangeStr
close(fail1); // Сохранение и закрытие файла
close(fail2); // Сохранение и закрытие файла
end.
}
{
program part2_z13;
var fail1, fail2 : text;
var i : Integer;
var str : String;
const n = 10;
var randDigits : array [1..n] of Integer;
var sortDigits : array [1..n] of Integer;
begin
  assign(fail1, 'f.txt');
  rewrite(fail1);
  for i := 1 to n do
    randDigits[i] := random(1,10);
  for i := 1 to n do
    write(fail1, randDigits[i], ' ');
  close(fail1);
  for i := n downto 1 do
    str := str + randDigits[i] + ' ';
  assign(fail2, 'g.txt');
  rewrite(fail2);
  write(fail2, str);
  close(fail2);
end.
}
{
program part2_z5;
var fail1, fail2, fail3 : text;
var str : String;
begin
  assign(fail1, 'f.txt'); // Назначаем переменной fail1 физический файл f
  assign(fail2, 'g.txt'); // Назначаем переменной fail2 физический файл g
  reset(fail1); // Открывает файл для чтения
  reset(fail2); // Открывает файл для чтения
  assign(fail3, 'h.txt'); // Назначаем переменной fail3 физический файл h
  rewrite(fail3); // Открываем файл для запси
  read(fail1, str); // Считываем данные fail1, записываем в переменную str
  writeln(fail3, str); // Записываем в fail3 значения переменной str
  read(fail2, str); // Считываем данные fail2, записываем в переменную str
  writeln(fail3, str); // Записываем в fail3 значения переменной str
  close(fail1); // Сохраняем и закрываем файл
  close(fail2); // Сохраняем и закрываем файл
  close(fail3); // Сохраняем и закрываем файл
end.
}