{
program z13;

Type assortim = record
  name : String; // Название игрушки
  cost : Real; // Стоимость игрушки
  age : Integer; // Возрастные ограничения
end;

var i, number : Integer;
var toy : array [1..10] of assortim; // Массив игрушек типа : assortim (record) 
var maxCost : Real; // Максимальная стоимость игрушки
var maxCostMinusOne : Real; // Максимальная стоимость игрушки минус 1
begin
  write('Введите количество записей: '); readln(number); // Вывод сообщея в консоль. Запрос ввода
  for i := 1 to number do
  begin
    write('Введите название ', i, ' игрушки: '); // Вывод сообщея в консоль.
    readln(toy[i].name); // Запрос ввода названия игрушки
    write('Введите стоимость ', i, ' игрушки: '); // Вывод сообщея в консоль.
    readln(toy[i].cost); // Запрос ввода
    write('Введите возрастные ', i, ' ограничения: '); // Вывод сообщея в консоль.
    readln(toy[i].age); // Запрос ввода
  end;
  maxCost := toy[1].cost; // maxCost инициализируется стоймостью первой игрушки
  for i := 1 to number do
    if toy[i].cost >= maxCost then // Если стоймость игрушки[i] больше переменной maxCost 
      maxCost := toy[i].cost; // В maxCost записывается эта стоймость
  maxCostMinusOne := maxCost - 1; // От maxCost отнимается 1 и число записывается в maxCostMinusOne
  writeln('Названия наиболее дорогих игрушек:');
  for i := 1 to number do // Цикл выводит в консоль названия дорогих игрушек
    if (toy[i].cost >= maxCostMinusOne) and (maxCost >= toy[i].cost) then
      writeln('Игрушка: ', toy[i].name, ' стоимость: ', toy[i].cost);
  writeln('Названия игрушек для детей возраста 4 - 10 лет:');
  for i := 1 to number do // Цикл выводит в консоль названия игрушек для детей возраста 4 - 10 лет
    if (toy[i].age >= 4) and (10 >= toy[i].age) then
      writeln('Игрушка: ', toy[i].name, ' возрастное ограничение: ', toy[i].age);
end.
}
{
program z5;

Type Bagaj = record
  numberOfItems : Integer; // Количество вещей (Кол-во предметов)
  weight : Real; // Вес (Масса)
end;
var i, number : Integer;
var passenger : array[1..10] of Bagaj;

begin
  write('Введите количество записей: '); readln(number); // Вывод сообщея в консоль. Запрос ввода
  for i := 1 to number do
    begin
    write('Введите количество вещей ', i, ' пассажира : ');
    read(passenger[i].numberOfItems);
    write('Введите вес (кг1) багажа ', i, ' пассажира : ');
    read(passenger[i].weight);
    end;
  for i := 1 to number do
    if (passenger[i].numberOfItems = 1) and (30 > passenger[i].weight) then
      writeln('Пассажир ', i, ' имеет кол-во вещей = ', passenger[i].numberOfItems, ' весом = ', passenger[i].weight, ' кг.');
end.
}