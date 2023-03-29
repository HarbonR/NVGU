{
program part1Z_13;

var
  str, s: String; // Обявление переменных типа String

var
  i: Integer; // Обявление переменной типа Integer

begin // Тело программы
  i := 1; // Инициализация переменной i
  str := 'abc(def)ghi'; // Инициализация переменной str
  while i <= length(str) do // Выполнять пока i не будет <= длинны str
  begin
    s := s + str[i]; // Добавляет к переменной s символы str с индексом i
    i := i + 1; // Выполняется инкремент
    if i = pos('(', str) then // Если i = индексу символа '(' str тогда
      while i <= pos(')', str) do // Выполнять пока i не будет <= индексу ')' str
        i := i + 1; // Выполняется инкремент
  end;
  writeln(s); // Вывод результата на консоль
end.
}
{
program part1Z_13;

var
  str, ch: String; // Обявление переменных типа String

var
  i: Integer; // Обявление переменной типа Integer

begin
  i := 1; // Инициализация переменной i
  str := 'abc(def)ghi'; // Инициализация переменной str
  ch := str[((pos(')', str)) + 1)]; // Присваевает символ ')' + 1 str
  while i <= length(str) do // Выполнять пока i не будет <= длинны str
  begin
    i := i + 1; // Выполняется инкремент
    if i = pos('(', str) then // Если i = индексу символа '(' str тогда
      while str[i] <> ch do // Пока символ индекса str не равен символу ch, выполнять
        delete(str, i, 1); // Удалять 1 символ str под индексом i 
  end;
  writeln(str); // Вывод результата на консоль
end.
}
{
program part1Z_13;

var
  str: String; // Обявление переменных типа String

var
  i: Integer; // Обявление переменной типа Integer

begin
  str := 'abc(def)ghi'; // Инициализация переменной str
  i := pos('(', str); // Присваевает индекс символа '(' str
  delete(str, i, pos(')', str) - i + 1); // Удаляет символы str с индекса i, колличеством: символ ')' str - индекс i + 1
  write(str); // Вывод результата на консоль
end.
}
{
program part1Z_23;

var
  str, s: String; // Обявление переменных типа String

var
  i: Integer; // Обявление переменных типа String

begin
  str := 'abc:def'; // Инициализация переменной str
  for i := pos(':', str) to length(str) do // Цикл с счетчиком от ':' до длинны str 
    s := s + str[i]; // Переменная s = s + символ str индекса i
  write(s); // Вывод результата в консоль
end.
}
{
program part2Z_13;

var
  str, str1, minStr: String; // Обявление переменных типа String

var
  i: Integer; // Обявление переменной типа Integer

begin
  str := 'abcdef abcd abc abcde ab '; // Инициализация переменной str
  minStr := str; // Переменная minStr приравнивается к str
  for i := 1 to length(str) do // Цикл с счетчиком от 1 до длинны str
  begin // Тело цикла
    if str[i] = ' ' then // Если индекс i str = пробелу выполнить
    begin // Тело условия
      if str1 <= minStr then
        minStr := str1;
      str1 := ''; // Вернуть переменную в исходное состояние
    end
    else // Иначе
      str1 := str1 + str[i] // Str1 = Str1 + символ str индекса i
  end;
  writeln('Самое короткое слово в предложении: ', minStr); // Вывод результата в консоль
end.
}
{
program part2Z_23;
var str, str1, symmetricStr : String; // Обявление переменных типа String
var i : Integer; // Обявление переменной типа Integer
begin // Тело программы
  str := 'abcde abcd abc ab a '; // Инициализация переменной str
  for i := 1 to length(str) do // Цикл с счетчиком от 1 до длинны str
  begin // Тело цикла
    if str[i] = ' ' then // Если индекс i str = пробелу выполнить
      begin // Тело условия
      if length(str1) mod 2 = 0 then // Если отсаток от деления на 2 = 0 выполнить
        begin
        symmetricStr := str1; // Прировнять переменную symmetricStr к str1
        break; // Выйти из цикла
        end;
      str1 := ''; // Вернуть переменную в исходное состояние
      end
    else
      str1 := str1 + str[i]; // Str1 = Str1 + символ str индекса i
  end;
  writeln('Первое симметричное слово в предложении: ',symmetricStr); // Вывод результата в консоль
end.
}
{
program part2Z_23;

var
  str, str1, symmetricStr, a1: String; // Обявление переменных типа String

var
  i, a: Integer; // Обявление переменной типа Integer

begin // Тело программы
  str := 'abcde abbs abba ab a '; // Инициализация переменной str
  for i := 1 to length(str) do // Цикл с счетчиком от 1 до длинны str
  begin // Тело цикла
    if str[i] = ' ' then // Если индекс i str = пробелу выполнить
    begin // Тело условия
      if length(str1) mod 2 = 0 then // Если количество букв в свове четное выполнить
      begin // Тело условия
        for a := length(str1) downto 1 do // Отзеркаливает слово переменной str1
          a1 := a1 + str1[a];
        if str1 = a1 then // Если слово переменной str1 = отзеркаленному слову переменной a1 выполнить
        begin
          symmetricStr := str1; // Прировнять переменную symmetricStr к str1
          break; // Выйти из цикла
        end
        else
          a1 := ''; // Вернуть переменную в исходное состояние
      end;
      str1 := ''; // Вернуть переменную в исходное состояние
    end
    else
      str1 := str1 + str[i]; // Str1 = Str1 + символ str индекса i
  end;
  writeln('Первое симметричное слово в предложении: ', symmetricStr); // Вывод результата в консоль
end.
}