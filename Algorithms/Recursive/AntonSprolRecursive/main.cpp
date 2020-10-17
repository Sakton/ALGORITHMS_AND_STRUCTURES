#include <algorithm>
#include <forward_list>
#include <iostream>
#include <string>
#include <vector>

// 6.1
int PositiveArraySumm( int arr[], int sz );
int PositiveArraySummRecursiveTail( int arr[], int sz );
int PositiveArraySummRecursiveHead( int arr[], int sz );

// 6.2
bool parity( const std::string& str );
bool parityRecursiveTail( const std::string& str, int sz );
bool parityRecursiveHead( const std::string& str, int sz );

// 6.3
int CountsElementsInArray( std::vector< int >& arr, int el );
int CountsElementsInArrayTail( std::vector< int >& arr, int el );
int CountsElementsInArrayHead( std::vector< int >& arr, int el );

// 6.4 Набор задач с сайта https://server.179.ru/tasks/training/recursion.html
// A: От 1 до n. Дано натуральное число n. Выведите все числа от 1 до n
void printNnum( int n );
// B: От A до B. Даны два целых числа A и В (каждое в отдельной строке).
//Выведите все числа от A до B включительно, в порядке возрастания, если A < B,
//или в порядке убывания в противном случае.
void printNumInterval( int a, int b );
// C: Функция Аккермана
//В теории вычислимости важную роль играет функция Аккермана A(m,n),
//определенная следующим образом: Даны два целых неотрицательных числа m и n,
//каждое в отдельной строке. Выведите A( m, n )
int ankerman( int m, int n );
// D: Точная степень двойки
//Дано натуральное число N. Выведите слово YES, если число N является точной
//степенью двойки, или слово NO в противном случае. Операцией возведения в
//степень пользоваться нельзя!
void stepen2( int n );
void stepen2( int n, int recursive );
// E:Дано натуральное число N. Вычислите сумму его цифр.
//При решении этой задачи нельзя использовать строки, списки, массивы( ну и
//циклы, разумеется ).
int summNumeralNumberTail( int n );
int summNumeralNumberHead( int n );
// F: Цифры числа справа налево
//Дано натуральное число N. Выведите все его цифры по одной, в обратном порядке,
//разделяя их пробелами или новыми строками. При решении этой задачи нельзя
//использовать строки, списки, массивы (ну и циклы, разумеется). Разрешена
//только рекурсия и целочисленная арифметика.
void reverseNumTail( int num );
// G:Цифры числа слева направо
void reverseNumHead( int num );
// H: Проверка числа на простоту
//Дано натуральное число n>1. Проверьте, является ли оно простым. Программа
//должна вывести слово YES, если число простое и NO, если число составное.
//Алгоритм должен иметь сложность O(√n).
void prosotoeChislo( int n, int delitel );
// I: Разложение на множители
//Дано натуральное число n>1. Выведите все простые делители этого числа в
//порядке неубывания с учетом кратности. Алгоритм должен иметь сложность O(√n).
void razlogenieNaMnogiteli( int n, int delitel );
// J: Палиндром
//Дано слово, состоящее только из строчных латинских букв. Проверьте, является
//ли это слово палиндромом. Выведите YES или NO. При решении этой задачи нельзя
//пользоваться циклами, в решениях на питоне нельзя использовать срезы с шагом,
//отличным от 1.
void palindrom( const std::string& string );
// K: Вывести нечетные числа последовательности
//Дана последовательность натуральных чисел (одно число в строке), завершающаяся
//числом 0. Выведите все нечетные числа из этой последовательности, сохраняя их
//порядок. В этой задаче нельзя использовать глобальные переменные и передавать
//какие-либо параметры в рекурсивную функцию. Функция получает данные, считывая
//их с клавиатуры. Функция не возвращает значение, а сразу же выводит результат
//на экран. Основная программа должна состоять только из вызова этой функции.
void nechethyeChisla( );
// L: Вывести члены последовательности с нечетными номерами
//Дана последовательность натуральных чисел (одно число в строке), завершающаяся
//числом 0. Выведите первое, третье, пятое и т.д. из введенных чисел.
//Завершающий ноль выводить не надо. В этой задаче нельзя использовать
//глобальные переменные и передавать какие - либо параметры в рекурсивную
//функцию.Функция получает данные, считывая их с клавиатуры.Функция не
//возвращает значение, а сразу же выводит результат на экран.Основная программа
//должна состоять только из вызова этой функции
void nechetnyeNomera( );
// M: Максимум последовательности
//Дана последовательность натуральных чисел( одно число в строке ),
//завершающаяся числом 0. Определите наибольшее значение числа в этой
//последовательности.
//В этой задаче нельзя использовать глобальные переменные и передавать какие -
//либо параметры в рекурсивную функцию.Функция получает данные, считывая их с
//клавиатуры.Функция возвращает единственное значение : максимум считанной
//последовательности.Гарантируется, что последовательность содержит хотя бы одно
//число( кроме нуля ).
int maxInSet( );
// N: Среднее значение последовательности
//Дана последовательность натуральных чисел( одно число в строке ),
//завершающаяся числом 0. Определите среднее значение элементов этой
//последовательности( без учета последнего нуля ).
//В этой задаче нельзя использовать глобальные переменные.Функция получает
//данные, считывая их с клавиатуры, а не получая их в виде параметра.В программе
//на языке Python функция возвращает кортеж из пары чисел : число элементов в
//последовательности и их сумма.В программе на языке C++ результат записывается
//в две переменные, которые передаются в функцию по ссылке. Гарантируется, что
//последовательность содержит хотя бы одно число( кроме нуля ).
double srednee( int& summ, int& count );
// O: Второй максимум
//Дана последовательность натуральных чисел (одно число в строке), завершающаяся
//числом 0. Определите значение второго по величине элемента в этой
//последовательности, то есть элемента, который будет наибольшим, если из
//последовательности удалить наибольший элемент. В этой задаче нельзя
//использовать глобальные переменные.Функция получает данные, считывая их с
//клавиатуры, а не получая их в виде параметра.В программе на языке Python
//функция возвращает результат в виде кортежа из нескольких чисел и функция
//вообще не получает никаких параметров.В программе на языке C++ результат
//записывается в переменные, которые передаются в функцию по ссылке.Других
//параметров, кроме как используемых для возврата значения, функция не получает.
//Гарантируется, что последовательность содержит хотя бы два числа( кроме нуля
//).
void secondMax( int& maximum1, int& maximum2 );
// P: Количество элементов, равных максимуму
//Дана последовательность натуральных чисел( одно число в строке ),
//завершающаяся числом 0. Определите, какое количество элементов этой
//последовательности, равны ее наибольшему элементу.
//В этой задаче нельзя использовать глобальные переменные.Функция получает
//данные, считывая их с клавиатуры, а не получая их в виде параметра.В программе
//на языке Python функция возвращает результат в виде кортежа из нескольких
//чисел и функция вообще не получает никаких параметров.В программе на языке C++
//результат записывается в переменные, которые передаются в функцию по
//ссылке.Других параметров, кроме как используемых для возврата значения,
//функция не получает. Гарантируется, что последовательность содержит хотя бы
//одно число( кроме нуля ).
void countMax( int& cnt, int& mx );
// Q: Количество единиц
//Дана последовательность натуральных чисел( одно число в строке ),
//завершающаяся двумя числами 0 подряд.Определите, сколько раз в этой
//последовательности встречается число 1. Числа, идущие после двух нулей,
//необходимо игнорировать. В этой задаче нельзя использовать глобальные
//переменные и параметры, передаваемые в функцию.Функция получает данные,
//считывая их с клавиатуры, а не получая их в виде параметров
int countOneInSequence( );
// R: Треугольная последовательность
//Дана монотонная последовательность, в которой каждое натуральное число k
//встречается ровно k раз : 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, ... По данному
//натуральному n выведите первые n членов этой последовательности.Попробуйте
//обойтись только одним циклом for
void iterativeSequence( int n );
void recursiveSequence( int n );
// S: Заданная сумма цифр
//Даны натуральные числа k и s. Определите, сколько существует k-значных
//натуральных чисел, сумма цифр которых равна d. Запись натурального числа не
//может начинаться с цифры 0. В этой задаче можно использовать цикл для перебора
//всех цифр, стоящих на какой - либо позиции.
int iterativeSumNumber( int len, int searchSum );
int recursiveSumNumber( int len, int searchSum, int k, int sum );
// T: Без двух нулей
//Даны числа a и b. Определите, сколько существует последовательностей из a
//нулей и b единиц, в которых никакие два нуля не стоят рядом.
int countStringNone2ZeroBeside( int countZero, int countOne );
//Доп. рекурисивно вывести битовые строки к = 5
void bitString( int k, int curLen );

// U: Разворот числа
//Дано число n, десятичная запись которого не содержит нулей. Получите число,
//записанное теми же цифрами, но в противоположном порядке. Фунция должна
//возвращать целое число, являющееся результатом работы программы, выводить
//число по одной цифре нельзя.
int iterativeReversial( int n );
int reversial( int n, int buffer );

// 6.5
int PositiveListSumm( std::forward_list< int >& list );
int PositiveListSummRecursiveTail( std::forward_list< int >& list,
                                   std::forward_list< int >::iterator& it );
int PositiveListSummRecursiveHead( std::forward_list< int >& list,
                                   std::forward_list< int >::iterator& it );

// 6.6
bool parityList( std::forward_list< int >& bitStr );
bool parityListRecursiveTail( std::forward_list< int >& bitStr,
                              std::forward_list< int >::const_iterator& it );
bool parityListRecursiveHead( std::forward_list< int >& bitStr,
                              std::forward_list< int >::const_iterator& it );

// 6.7
int CountsElementsInList( std::forward_list< int >& lst, int x );
int CountsElementsInListTail( std::forward_list< int >& lst, int x,
                              std::forward_list< int >::iterator& it );
int CountsElementsInListHead( std::forward_list< int >& lst, int x,
                              std::forward_list< int >::iterator& it );

// 6.9
bool IsHeap( int arr[], int sz, int curIndex );

// 6.10
bool IsBinaryTree( int arr[], int sz, int curIndex );

int main( ) {
  //к заданию 6.1
  /*
        int arr[ ]{ -1, 1, -1, 1, -1, 1, -1, 1, -1, 1 };
        std::cout << PositiveArraySumm( arr, 10 ) << std::endl;
        std::cout << PositiveArraySummRecursiveTail( arr, 10 ) << std::endl;
        std::cout << PositiveArraySummRecursiveHead( arr, 10 ) << std::endl;
        */

  //к задаче 6.2
  /*
        std::string bitStr{ "110011001" };
        std::cout << std::boolalpha << parity( bitStr ) << std::endl;
        std::cout << std::boolalpha << parityRecursiveTail( bitStr, bitStr.size(
     ) ) << std::endl; std::cout << std::boolalpha << parityRecursiveHead(
     bitStr, bitStr.size( ) ) << std::endl;
        */

  //к задаче 6.3
  /*
        std::vector<int> e{1,2,3,4,5,6,6,6,6,5,4,3,2,1};
        std::cout << CountsElementsInArray( e, 6 ) << std::endl;
        std::cout << CountsElementsInArrayTail( e, 6 ) << std::endl;
        std::cout << CountsElementsInArrayHead( e, 6 ) << std::endl;
        */

  /*
        //к зачачам 6.4
        //A:
        printNnum( 5 );
        //B:
        printNumInterval( 1, 10 );
        std::cout << std::endl;
        printNumInterval( 10, 1 );
        //	C:
        std::cout << ankerman( 2, 2 ) << std::endl;
        //	D:
        stepen2( 16, 1 );
        //	E:
        std::cout << summNumeralNumberTail( 179 ) << std::endl;
        std::cout << summNumeralNumberHead( 179 ) << std::endl;
        //	F: G:
        reverseNumTail( 179 );
        std::cout << std::endl;
        reverseNumHead( 179 );
        //	H:
        prosotoeChislo( 2, 2 );
        prosotoeChislo( 4, 2 );
        //	I:
        razlogenieNaMnogiteli( 18, 2 );
        //	J:
        palindrom( "radar" );
        palindrom( "raar" );
        palindrom( "raarr" );
        //	K:
        nechethyeChisla( );
        //	L:
        nechetnyeNomera( );
        //	M:
        std::cout << " ==> " << maxInSet( ) << std::endl;
        //N:
        int sum = 0;
        int cnt = 0;
        std::cout << " ==> " << srednee( sum, cnt ) << std::endl;
        //O:
        int mx1 = 0;
        int mx2 = 0;
        secondMax( mx1, mx2 );
        //std::cout << mx1 << std::endl;
        std::cout << " ==> " << mx2 << std::endl;
        //P:
        int count = 0;
        int max = 0;
        countMax( count, max );
        std::cout << "count = " << count << std::endl;
        std::cout << "max = " << max << std::endl;
        //Q:
        std::cout << "res = " << countOneInSequence( ) << std::endl;
        //std::cin.clear( );
        //std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        //std::cout << "res = " << countOneInSequence( ) << std::endl;
        //R:
        //iterativeSequence( 5 );
        recursiveSequence( 11 );
        //S:
        std::cout << iterativeSumNumber( 3, 15 ) << std::endl;
        int sum = 0;
        int res = 0;
        std::cout << recursiveSumNumber( 3, 15, 0, sum );
        //T:
        std::cout << countStringNone2ZeroBeside( 2, 2 );
        //допка
        bitString( 0, 5 );
        //std::cout << iterativeReversial( 123 );
        std::cout << reversial( 123, 0 );
        std::forward_list<int> lst{ 5,-5,5,-5,5,-5 };
        std::cout << PositiveListSumm( lst ) << std::endl;
        std::forward_list<int>::iterator it = lst.begin();
        std::cout << PositiveListSummRecursiveHead( lst, it ) << std::endl;
        it = lst.begin();
        std::cout << PositiveListSummRecursiveTail( lst, it ) << std::endl;
        std::forward_list<int> lst{ 0,1,1,1,0,0,1,0,1,1,0,1 };
        std::cout << std::boolalpha << parityList( lst ) << std::endl;
        std::forward_list<int>::iterator it = lst.begin( );
        std::cout << std::boolalpha << parityListRecursiveTail( lst, it ) <<
std::endl; it = lst.begin( ); std::cout << std::boolalpha <<
parityListRecursiveHead( lst, it ) << std::endl;
        //6.7
        try {
                std::forward_list<int> list{ 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5 };
                std::cout << CountsElementsInList( list, 5 ) << std::endl;
                std::forward_list<int>::iterator it = list.begin();
                std::cout << CountsElementsInListTail( list, 5, it ) <<
std::endl; it = list.begin( ); std::cout << CountsElementsInListHead( list, 5,
it ) << std::endl;

} catch ( const std::exception & e) {
  std::cout << e.what( );
} catch (...) {
  std::cout << "???";
}

*/

  // int hp[ ]{ 2,5,1,6,4,3,8,9 };
  // std::cout << std::boolalpha << IsHeap( hp, 8, 0 ) << std::endl;
  int hp[] { 50, 40, 30, 20, 10, 6, 8, 7, 9 };
  std::cout << std::boolalpha << IsHeap( hp, 9, 0 ) << std::endl;
}

// 6.1
int PositiveArraySumm( int arr[], int sz ) {
  int summ = 0;
  for ( int i = 0; i < sz; ++i )
    if ( arr[ i ] > 0 ) summ += arr[ i ];
  return summ;
}
// 6.1
int PositiveArraySummRecursiveTail( int arr[], int sz ) {
  //
  if ( sz == 0 ) return 0;  // base
  int summ = 0;
  if ( arr[ sz - 1 ] > 0 ) summ = arr[ sz - 1 ];
  return summ + PositiveArraySummRecursiveTail( arr, sz - 1 );
}
// 6.1
int PositiveArraySummRecursiveHead( int arr[], int sz ) {
  if ( sz == 0 ) return 0;  // base
  int summ = PositiveArraySummRecursiveHead( arr, sz - 1 );
  if ( arr[ sz - 1 ] > 0 ) summ += arr[ sz - 1 ];
  return summ;
}

// 6.2
bool parity( const std::string& str ) {
  // int bits = 0;
  // for ( int i = 0; i < str.size( ); ++i )
  //	if ( str[ i ] == '1' ) ++bits;
  // return !( bits % 2 == 0 );
  bool res = false;
  for ( int i = 0; i < str.size( ); ++i )
    if ( str[ i ] == '1' ) res = !res;
  return res;
}
// 6.2
bool parityRecursiveTail( const std::string& str, int sz ) {
  if ( sz == 0 ) return false;
  bool res = ( str[ sz - 1 ] == '1' ) ? true : false;
  bool x = parityRecursiveTail( str, sz - 1 );
  if ( x ) res = !res;
  return res;
}
// 6.2
bool parityRecursiveHead( const std::string& str, int sz ) {
  if ( sz == 0 ) return false;
  bool x = parityRecursiveHead( str, sz - 1 );
  bool res = ( str[ sz - 1 ] == '1' ) ? true : false;
  if ( x ) res = !res;
  return res;
}

// 6.3
int CountsElementsInArray( std::vector< int >& arr, int el ) {
  int count = 0;
  for ( int elmnt : arr ) {
    if ( elmnt == el ) ++count;
  }
  return count;
}

int CountsElementsInArrayTail( std::vector< int >& arr, int el ) {
  if ( arr.size( ) == 0 ) return 0;
  int count = 0;
  int elem = arr.back( );
  arr.pop_back( );
  if ( elem == el ) ++count;
  int reasRec = CountsElementsInArrayTail( arr, el );
  arr.push_back( elem );
  return count + reasRec;
}

int CountsElementsInArrayHead( std::vector< int >& arr, int el ) {
  if ( arr.size( ) == 0 ) return 0;
  int elem = arr.back( );
  arr.pop_back( );
  int reasRec = CountsElementsInArrayHead( arr, el );
  arr.push_back( elem );
  int cnt = 0;
  if ( elem == el ) ++cnt;
  return cnt + reasRec;
}

// 6.4 Набор задач с сайта https://server.179.ru/tasks/training/recursion.html
// A
void printNnum( int n ) {
  if ( n == 0 ) return;
  printNnum( n - 1 );
  std::cout << n << " ";
}
// B
void printNumInterval( int a, int b ) {
  //базовый случай: если интервалы равны, то печатаем любой из них и выход
  if ( a == b ) {
    std::cout << a << " ";
    return;
  }
  if ( a < b ) {
    printNumInterval( a, b - 1 );
    std::cout << b << " ";
  } else {
    std::cout << a << " ";
    printNumInterval( a - 1, b );
  }
}

// C
int ankerman( int m, int n ) {
  if ( m == 0 ) return n + 1;
  if ( m > 0 && n == 0 )
    return ankerman( m - 1, 1 );
  else if ( m > 0 && n > 0 )
    return ankerman( m - 1, ankerman( m, n - 1 ) );
}

// D:
void stepen2( int n ) {
  //тут локальная переменная для сравнения
  for ( int i = 1; i <= n; i *= 2 ) {
    if ( i == n ) {
      std::cout << "YES" << std::endl;
      return;
    }
  }
  std::cout << "NO" << std::endl;
}

//тут пришлось ввести параметр по которому вести рекурсию
void stepen2( int n, int recursive ) {
  if ( recursive == n ) {
    std::cout << "YES" << std::endl;
    return;
  }
  if ( recursive > n ) {
    std::cout << "NOT" << std::endl;
    return;
  }
  stepen2( n, recursive * 2 );
}

// E:
int summNumeralNumberTail( int n ) {
  //базисная ветвь
  if ( n == 0 ) return 0;
  //рекурсивная ветвь
  return ( n % 10 + summNumeralNumberTail( n / 10 ) );
}

int summNumeralNumberHead( int n ) {
  //базисная ветвь
  if ( n == 0 ) return 0;
  return ( summNumeralNumberHead( n / 10 ) + n % 10 );
}

// F:
void reverseNumTail( int num ) {  //прямой порядок
  if ( num == 0 )
    return;  //базовый случай, если число равно нлю ничего выводить не надо
  std::cout << ( num % 10 ) << " ";
  reverseNumTail( num / 10 );
}
// G:
void reverseNumHead( int num ) {  //обратный порядок
  if ( num == 0 )
    return;  //базовый случай, если число равно нлю ничего выводить не надо
  reverseNumHead( num / 10 );
  std::cout << ( num % 10 ) << " ";
}

// H:
void prosotoeChislo( int n, int delitel ) {
  //Вводим параметр делитель по которому будем вести рекурсию
  //проверку на 0 и тд. опускаем
  if ( n < delitel * delitel ) {
    //если делитель числа так и не найден, число не может быть больше квадрата
    //делителя
    std::cout << "YES" << std::endl;
    return;
  } else if ( n % delitel == 0 ) {
    std::cout << "NO" << std::endl;
    return;
  }
  prosotoeChislo( n, delitel + 1 );
}

// I:
void razlogenieNaMnogiteli( int n, int delitel ) {
  //Вводим делитель по которому ведем рекурсию, так как сама по себе задача не
  //сводится к меньшей базовый случай, проверки на 0 и тд пропускаем
  if ( n == 0 )
    return;
  else if ( n % delitel == 0 ) {
    std::cout << delitel << "  ";
    razlogenieNaMnogiteli( n / delitel, delitel );
  } else {
    razlogenieNaMnogiteli( n, delitel + 1 );
  }
}

// J:
void palindrom( const std::string& string ) {
  //задача сводится к сравнению крайних символов строки
  //если они совпвдают, то рассматриваем подстроку без этих символов
  //Базовые случаи - строка из 1 символа или пустая - это палиндромы
  if ( string.size( ) < 1 ) {
    std::cout << "YES" << std::endl;
    return;
  } else if ( string[ 0 ] != string.back( ) ) {
    std::cout << "NO" << std::endl;
    return;
  } else {
    palindrom( string.substr( 1, string.size( ) - 2 ) );
  }
}

// K:
void nechethyeChisla( ) {
  int x = -1;
  std::cin >> x;
  if ( x <= 0 ) return;
  if ( x % 2 != 0 ) std::cout << " ==> " << x << std::endl;
  nechethyeChisla( );
}

// L:
void nechetnyeNomera( ) {
  int x = -1;
  std::cin >> x;
  if ( x <= 0 ) return;
  static int count;  //статическая переменная считается за глобальную? хотя про
                     //эту переменную знает только функция
  ++count;
  if ( count % 2 != 0 ) std::cout << " ==> " << x << std::endl;
  nechetnyeNomera( );
}

// M:
int maxInSet( ) {
  int x = -1;
  std::cin >> x;
  if ( x == 0 ) return 0;
  int res = maxInSet( );
  return ( x > res ) ? x : res;
}

// N:
double srednee( int& summ, int& count ) {
  int x = 0;
  std::cin >> x;
  if ( x <= 0 )
    return ( double( summ ) / double( count ) );
  else
    return srednee( summ += x, ++count );
}

// 0:
//Решение: в макс2 храним самый максимум, если встретилось число больше самого
//максимума, то старый максимум сохраняем в макс2, а новый в макс1 (), иначе
//если появилось число больше макс2 но меньше или такоеже как макс1, то пишем
//его в макс2
void secondMax( int& maximum1, int& maximum2 ) {
  int x = 0;
  std::cin >> x;
  if ( x == 0 ) return;
  secondMax( maximum1, maximum2 );
  if ( x > maximum1 ) {
    maximum2 = maximum1;
    maximum1 = x;
  } else if ( x > maximum2 && x <= maximum1 ) {
    maximum2 = x;
  }
}

// P:
void countMax( int& cnt, int& mx ) {
  int x = 0;
  std::cin >> x;
  if ( x == 0 ) return;
  if ( x > mx ) mx = x;
  countMax( cnt, mx );
  if ( x == mx ) ++cnt;
}

// Q:
int countOneInSequence( ) {
  //статическая переменная является общей для функции, повторный вызов этой ф-ии
  //создаст новый экзкмпляр статической переменной прата с.443
  int x = -1;
  std::cin >> x;
  static int sum = 0;
  if ( x == 1 ) sum = x;
  if ( x == 0 ) --sum;
  if ( sum < 0 ) return 0;
  return x + countOneInSequence( );
}

// R:
void iterativeSequence( int n ) {
  int cnt = 0;
  for ( int i = 1; i <= n && cnt < n; ++i ) {
    for ( int j = 0; j < i && cnt < n; ++j, ++cnt ) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

void recursiveSequence( int n ) {
  if ( n <= 0 ) return;
  static int number = 1;
  for ( int i = 0; i < number && i < n; ++i )
    //пока i < номера, он же количество этих элементов в ряду, и меньше общего
    //количества выводиимых оставшихся элементов
    std::cout << number << " ";
  std::cout << std::endl;
  ++number;
  //тк. икремент номера произошел, а надо передать n за вычетом старого значения
  recursiveSequence( n - ( number - 1 ) );
}

// S:
int iterativeSumNumber( int len, int searchSum ) {
  //сумма цифр ищетсы на конкретной длине разрядов
  int start = std::pow( 10, len - 1 );
  int end = std::pow( 10, len );
  int count = 0;  //хранит количество совпадений суммы
  for ( int i = start; i < end; ++i ) {
    //тут выделяем из числа его составляющие
    int summa = 0;
    int t = i;
    while ( t != 0 ) {
      summa += t % 10;
      t /= 10;
    }
    //проверяем на сумму
    if ( searchSum == summa ) ++count;
  }
  return count;
}

int recursiveSumNumber( int len, int searchSum, int k, int sum ) {
  //надо проверить искомую сумму с найденой и если равны то вернуть 1
  //конечная сумма будет известна когда порядок достигнет заданного порядка
  //дополнительный параметр - текущций порядок числа k, и внешняя переменная с
  //текущей суммой значение суммы накапливается в параметре передаваемом их
  //функции к функции так же передается и k - это параметры рекурсии
  if ( k == len ) {
    //если при заданном порядке числа сумма равна заданной то это число считаем
    if ( searchSum == sum ) {
      return 1;
    } else {
      return 0;
    }
  }
  //если порядок числа = 0, то искомое число не может начинатся с нуля, для
  //этого случая
  int start = ( k == 0 ) ? 1 : 0;
  //перебираем цифры, и для каждой цифры вызываем фукцию, передавая исходные
  //параметры разряд + 1, и сумма уже как бы результирующая увеличенная на
  //проверяемую i int countRes = 0;
  int res = 0;
  for ( size_t i = start; i < 10; i++ ) {
    std::cout << i << " ";
    if ( k != len - 1 ) std::cout << std::endl;
    //сперва рекурсивные ф-ии откроются для первой тройки (до перврй k = len)
    //затем выход из рекурсии по базовому случаю последней ф-ии, но 2 предыдущие
    //не закрыты, и будет вызвана снова для (k == len) и тд. пока не пройдет
    //весь цикл, далее выход на уровень выше для k = len - 1, прейдет на новую
    //итерацию и снова для k = len  и т.д.
    res += recursiveSumNumber(
        len, searchSum, k + 1,
        ( sum + i ) );  // TODO ПОЧЕМУ sum += i дает неверный результат
  }
  return res;
}

//Доп. рекурисивно вывести битовые строки к = 5
void bitString( int k, int curLen ) {
  static std::vector< int > v;
  static int x = 0;
  if ( k == curLen ) {
    for ( int el : v ) std::cout << el;
    std::cout << std::endl;
    return;
  } else {
    v.push_back( 0 );
    bitString( k + 1, curLen );
    v.pop_back( );
    v.push_back( 1 );
    bitString( k + 1, curLen );
    v.pop_back( );
  }
}

// T:
int countStringNone2ZeroBeside( int countZero, int countOne ) {
  //Назовем последовательность из 0 и 1, в которой никакие две единицы не стоят
  //подряд, хорошей. Обозначим число хороших последовательностей длины k через
  //Fk .
  //Попытаемся теперь выразить количество хороших последовательностей длины k
  //через количества хороших последовательностей меньшей длины.Для этого
  //рассмотрим, как можно построить хорошую последовательность длины k.Если
  //последним символом этой последовательности выбрать 0, то в качестве
  //предыдущих k - 1 символов можно взять произвольную хорошую
  //последовательность длины k - 1. А таких последовательностей Fk - 1.Если же
  //последним символом выбрать 1, то на( k - 1 ) - ом месте 1 стоять не может и,
  //значит, там стоит 0. Тогда в качестве первых k - 2 символов можно взять
  // любую хорошую последовательность длины k - 2, а их количество Fk - 2.Таким
  //образом, находим, что Fk = Fk - 1 + Fk - 2.
  // http://www.problems.ru/view_problem_details_new.php?id=102778
  /*
        Если все единицы :
        f( 0, b ) = 1
                Если один ноль, остальные единицы :
        f( 1, b ) = b + 1
                Если больше одного нуля и нет единиц :
        f( > 1, 0 ) = 0
                Иначе либо последняя цифра - ноль, тогда предпоследняя -
     единица; либо последняя - единица. f( a, b ) = f( a - 1, b - 1 ) + f( a, b
     - 1 )
        */
  //базовые случаи
  //...Порядок важен
  // 2. Если количество нулей превышает количичество единиц на 2 ( 5 > x + 1 =>
  // x = 3 => 5 - 3 = 2 ) то построить нужную последовательность невозможно
  if ( countZero > countOne + 1 ) return 0;
  // 1. Символы кончились ????????????????????
  //если кончились нули, то осталась единица или наоборот ?
  if ( countZero == 0 || countOne == 0 ) return 1;
  //к искомой последовательности можно прийти 2 способами
  //если первый символ 0, то искомая хорошая последовательность начнется с 1,
  //и если с 1 то как обычно
  return countStringNone2ZeroBeside( countZero, countOne - 1 ) +
         countStringNone2ZeroBeside( countZero - 1, countOne - 1 );

  // if ( countZero > countOne + 1 ) return 0;
  // if ( countZero == 0 || countOne == 0 ) return 1;
  // return countStringNone2ZeroBeside( countZero, countOne - 1 ) +
  // countStringNone2ZeroBeside( countZero - 1, countOne - 1 );
}

// U:
int iterativeReversial( int n ) {
  int res = 0;
  while ( n > 0 ) {
    res = res * 10 + n % 10;
    n /= 10;
  }
  return res;
}

//задача решена через некую буферную переменную....но это было совсем не
//очевидно
int reversial( int n, int buffer ) {
  // if ( n == 0 ) return buffer;
  // reversial( n / 10, buffer * 10 + n % 10 );
  return ( n == 0 ) ? buffer : reversial( n / 10, buffer * 10 + n % 10 );
}

// 6.5
int PositiveListSumm( std::forward_list< int >& list ) {
  int sum = 0;
  for ( int el : list )
    if ( el > 0 ) sum += el;
  return sum;
}

int PositiveListSummRecursiveTail( std::forward_list< int >& list,
                                   std::forward_list< int >::iterator& it ) {
  if ( it == list.end( ) ) return 0;
  std::forward_list< int >::iterator curIterator = it;
  int x = ( *curIterator < 0 ) ? 0 : *curIterator;
  return x + PositiveListSummRecursiveTail( list, ++it );
}

int PositiveListSummRecursiveHead( std::forward_list< int >& list,
                                   std::forward_list< int >::iterator& it ) {
  if ( it == list.end( ) ) return 0;
  //сохранить копию текущего итератора, т.к. входящий итератор шагает до конца
  std::forward_list< int >::iterator curIter = it;
  int x = PositiveListSummRecursiveHead( list, ++it );
  int y = ( *curIter < 0 ) ? 0 : *curIter;
  return ( x + y );
}

// 6.6
bool parityList( std::forward_list< int >& bitStr ) {
  bool res = false;
  for ( int el : bitStr )
    if ( el == 1 ) res = !res;
  return res;
}

bool parityListRecursiveTail( std::forward_list< int >& bitStr,
                              std::forward_list< int >::const_iterator& it ) {
  if ( bitStr.empty( ) || it == bitStr.end( ) ) return false;
  std::forward_list< int >::const_iterator curIterator = it;
  bool x = parityListRecursiveTail( bitStr, ++it );
  bool res = ( *curIterator == 1 ) ? true : false;
  if ( x ) res = !res;
  return res;
}

bool parityListRecursiveHead( std::forward_list< int >& bitStr,
                              std::forward_list< int >::const_iterator& it ) {
  if ( bitStr.empty( ) || it == bitStr.end( ) ) return false;
  bool res = ( *it == 1 ) ? true : false;
  bool x = parityListRecursiveHead( bitStr, ++it );
  if ( x ) res = !res;
  return res;
}

// 6.7
int CountsElementsInList( std::forward_list< int >& lst, int x ) {
  int res = 0;
  for ( int el : lst )
    if ( el == x ) ++res;
  return res;
}

int CountsElementsInListTail( std::forward_list< int >& lst, int x,
                              std::forward_list< int >::iterator& it ) {
  if ( it == lst.end( ) ) return 0;
  // std::forward_list<int>::iterator curIter = it;
  int res = ( *it == x ) ? 1 : 0;
  return res + CountsElementsInListTail( lst, x, ++it );
}

int CountsElementsInListHead( std::forward_list< int >& lst, int x,
                              std::forward_list< int >::iterator& it ) {
  if ( it == lst.end( ) ) return 0;
  std::forward_list< int >::iterator curIter = it;
  int el = CountsElementsInListHead( lst, x, ++it );
  int res = ( *curIter == x ) ? 1 : 0;
  return res + el;
}

// 6.9
bool IsHeap( int arr[], int sz, int curIndex ) {
  if ( curIndex > ( sz - 1 ) / 2 ) return true;
  bool left = IsHeap( arr, sz, curIndex * 2 + 1 );
  bool right = IsHeap( arr, sz, curIndex * 2 + 2 );
  bool res = false;
  if ( ( arr[ curIndex ] < arr[ curIndex * 2 + 1 ] ) ||
       ( arr[ curIndex ] < arr[ curIndex * 2 + 2 ] ) )
    res = false;
  else {
    res = true;
  }
  return ( left && right && res );
}

// 6.10
bool IsBinaryTree( int arr[], int sz, int curIndex ) {}
