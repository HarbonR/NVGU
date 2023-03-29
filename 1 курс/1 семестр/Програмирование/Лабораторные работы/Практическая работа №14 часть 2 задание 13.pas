//==============================================================================
// Создаются новые типы
type
typeData = Integer; // Тип для поля Data
pointerList = ^typeList; // Тип указатель на запись
typeList = record // Тип запись
  data : typeData;
  nextElement : pointerList;
end;
listForPointerLists = record // Запись с полями для хранения указателей
  first : pointerList;
  last : pointerList;
end;
mnozh = set of 1..10; // тип множество
//==============================================================================
// Процедура заполнения списка элементами
procedure addElementToList (var inputList : listForPointerLists; var newElement : pointerList);
begin
  if inputList.first = nil then
  begin
    inputList.first := newElement;
    newElement^.nextElement := nil;
  end
  else
  begin
    inputList.last := newElement;
    inputList.last^.nextElement := inputList.first;
    inputList.first := inputList.last;
  end;
end;
//==============================================================================
// Цикл выводит список в консоль
  procedure wrList(inputList : listForPointerLists);
  var pointerListToNewElement : pointerList := inputList.first;
  begin
  While pointerListToNewElement <> nil do
  begin
    Write (pointerListToNewElement^.data, ' ');
    pointerListToNewElement:= pointerListToNewElement^.nextElement;
  end;
  end;
//==============================================================================
// Процедура рандомного заполнения листа
procedure randList(var inputList : listForPointerLists; number : Integer);
var i : Integer;
var newElement : pointerList;
begin
  for i := 1 to number do
  begin
    new(newElement);
    newElement^.data := random(1,10);
    addElementToList(inputList, newElement);
  end;
end;
//==============================================================================
// Процедура заполняет множество, данными из списка
  procedure wrList1(inputList : listForPointerLists; var inputMnozh : mnozh);
  var pointerListToNewElement : pointerList := inputList.first;
  begin
  While pointerListToNewElement <> nil do
  begin
    inputMnozh := inputMnozh + [pointerListToNewElement^.data];
    pointerListToNewElement:= pointerListToNewElement^.nextElement;
  end;
  end;
//==============================================================================
// Процедура заполняет список, данными из множества
  procedure wrList2(var inputList : listForPointerLists; var inputMnozh : mnozh);
  var newElement : pointerList;
  var i : Integer;
  begin
    for i := 1 to 10 do
      if i in inputMnozh then
      begin
        new(newElement);
        newElement^.data := i;
        addElementToList(inputList, newElement);
      end;
  end;
//==============================================================================
// Глобальные переменные
var oneList, twoList, threeList : listForPointerLists;
//==============================================================================
// Основная программа
begin
  var listMnozhOne, listMnozhTwo, listMnozhThree : mnozh;
  write('Первый список = ');
  randList(oneList, 5);
  wrList(oneList);
  writeln;
  write('Второй список = ');
  randList(twoList, 5);
  wrList(twoList);
  wrList1(oneList, listMnozhOne);
  wrList1(twoList, listMnozhTwo);
  listMnozhThree := listMnozhOne * listMnozhTwo;
  listMnozhOne := listMnozhOne - listMnozhThree;
  listMnozhTwo := listMnozhTwo - listMnozhThree;
  listMnozhThree := listMnozhOne + listMnozhTwo;
  wrList2(threeList, listMnozhThree);
  writeln;
  write('Третий список = ');
  wrList(threeList);
end.
//==============================================================================