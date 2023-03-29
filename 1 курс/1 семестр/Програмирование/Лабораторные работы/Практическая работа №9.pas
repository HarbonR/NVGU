{
program z13;

var
  vowel: set of Char;

var
  str: String;

var
  sotrtStr: String;

var
  i, j: Integer;

var
  ch: Char;

begin
  vowel := ['А', 'а', 'У', 'у', 'О', 'о', 'Ы', 'ы', 'Э', 'э', 'Е', 'е', 'Ё', 'ё', 'И', 'и', 'Ю', 'ю', 'Я', 'я']; // Множество глассных букв
  writeln('Введите текст:'); read(str); // Вывод сообщения. Запрос ввода в консоль
  for i := 1 to length(str) do
    if str[i] in vowel then // Если символ строки входит в множество vowel (Гласные)
      sotrtStr := sotrtStr + str[i]; // то этот символ записывается с строку sotrtStr
  for i := 1 to length(sotrtStr) do // Цикл сортирует строку sotrtStr по алфавиту
    for j := 1 to length(sotrtStr) - 1 do // АБВабв
      if sotrtStr[j] > sotrtStr[j + 1] then // Если первый символ больше чем второй
      begin
        ch := sotrtStr[j]; // символ записывается в переменную ch
        sotrtStr[j] := sotrtStr[j + 1]; // символ смещается
        sotrtStr[j + 1] := ch; // на одну единицу в право
      end;
  write(sotrtStr); // Вывод в консоль отсортированной, изменённой строки
end.
}
{
program z3;

var
  vowel: set of Char;

var
  consonants: set of Char;

var
  str: String;

var
  strVowel: String; // Строка гласных

var
  strConsonants: String; // Строка согласных

var
  i: Integer;

begin
  vowel := ['a', 'e', 'i', 'o']; // Множество глассных букв
  consonants := ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']; // Множество согласных букв
  writeln('Введите текст из строчных латинских букв:'); read(str); // Вывод сообщения. Запрос ввода в консоль
  for i := 1 to length(str) do
  begin
    if str[i] in vowel then // Если символ строки входит в множество vowel (Гласные)
      strVowel := strVowel + str[i]; // то этот символ записывается с строку strVowel
    if str[i] in consonants then // Если символ строки входит в множество consonants (Согласные)
      strConsonants := strConsonants + str[i]; // то этот символ записывается с строку strConsonants
  end;
  if length(strVowel) > length(strConsonants) then
    write('Гласных букв больше ', length(strVowel), ' > ', length(strConsonants))
  else if strVowel < strConsonants then
    write('Согласных букв больше ', length(strConsonants), ' > ', length(strVowel))
  else if strVowel = strConsonants then
    write('Гласных и согласных букв одинакого ', length(strVowel), ' = ', length(strConsonants));
end.
}
{
program z8;

begin
  var digits : Set of Integer; // Множество целых чисел
  var section : Set of Integer; // (Отрезок) Множество.
  var i, start, stop, number, x: Integer;
  writeln('Введите последовательность целых чисел:');
  write('Введите количество чисел которые вы хотите ввести = ');  read(number);
  write('Введите числа = ');
  for i := 1 to number do // Считывает и записывает числа в множество digits
  begin
    read(x);
    digits := digits + [x];
  end;
  writeln('Введите отрезок:');
  write('Введите начало отрезка = '); read(start);
  write('Введите конец отрезка = '); read(stop);
  for i := start to stop do // Записывает в множество числа отрезка
    section := section + [i];
  if digits = section then
    write('Является')
  else
    write('Не является');
end.
}