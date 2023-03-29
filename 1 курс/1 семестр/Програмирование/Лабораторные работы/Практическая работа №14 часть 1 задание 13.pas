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
// Цикл определяет чётные и не четные числа
procedure evenOddDigitsList (inputList: listForPointerLists; var outputList1, outputList2 : listForPointerLists);
var pointerListToNewElement : pointerList := inputList.first;
var newElement : pointerList;
begin
  While pointerListToNewElement<> nil do
    if pointerListToNewElement^.data mod 2 = 0 then
    begin
      new(newElement);
      newElement^.data := pointerListToNewElement^.data;
      addElementToList(outputList1, newElement);
      pointerListToNewElement:= pointerListToNewElement^.nextElement;
    end
    else
    begin
      new(newElement);
      newElement^.data := pointerListToNewElement^.data;
      addElementToList(outputList2, newElement);
      pointerListToNewElement:= pointerListToNewElement^.nextElement;
    end;
end;
//==============================================================================
// Цикл выводит список в консоль
  procedure wrList(inputList : listForPointerLists);
  var pointerListToNewElement : pointerList := inputList.first;
  begin
  While pointerListToNewElement<> nil do
  begin
    Write (pointerListToNewElement^.data, ' ');
    pointerListToNewElement:= pointerListToNewElement^.nextElement;
  end;
  end;
//==============================================================================
// Глобальные переменные
var oneList, twoList, threeList : listForPointerLists;
var newElement : pointerList; // Тип указатель
var i, number : Integer;
//==============================================================================
// Основная программа
begin
//==============================================================================
// Запрашивает ввод элементов первого списка
  write('Введите количество элементов исходного списка = '); read(number);
  write('Введите элементы = ');
  for i := 1 to number do // 
  begin
    new(newElement);
    read(newElement^.data);
    addElementToList(oneList, newElement);
  end;
//==============================================================================
  evenOddDigitsList(oneList, twoList, threeList);
  write('Список четных чисел = '); wrList(twoList);
  writeln;
  write('Список не четных чисел = '); wrList(threeList);
end.
//==============================================================================