#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <string.h>
#include <exception>
#include <ncurses.h>

void addHistory(std::vector<std::string>& history, std::string& operation)
{
  history.push_back(operation);
}
void showHistory(std::vector<std::string>& history)
{
  std::system("clear");
  std::puts("---------------------История ваших операций---------------------");
  std::cout << std::endl;
  int count{1};
  for(const auto& i : history)
  {
    std::cout << count << ". ";
    std::cout << i << std::endl;
    ++count;
  }
  std::cout << std::endl;
}
class CorrectRub : public std::exception
{
    std::string msg {""}; 

public:

    CorrectRub(std::string msg) : msg(msg) { }

    const char* what()const noexcept override {return msg.c_str();}

    virtual ~CorrectRub(){ }
};
int plus_plus_balance(int b, int sum) {return b += sum;}

int minus_minus_balance(int b, int min) {b -= min;return b < 0 ? -1 : b;}

std::string correct(int sum)
{
    int number{};
    if(10 >= sum <= 99)
        number = sum % 10;
    else if(100>=sum<=999)
        number = sum % 100;
    else if(1000>=sum<=9999)
        number = sum % 1000;
    else if(10000>=sum<=99999)
        number = sum % 10000;
    else if(100000>=sum<=999999)
        number = sum % 100000;
    else if(1000000>=sum<=9999999)
        number = sum % 1000000;
    else if(10000000>=sum<=99999999)
        number = sum % 10000000;
    switch (number)
    {
      case 0: 
        return "рублей";
      case 1: 
        return "рубль";
      case 2:   
        return "рубля";
      case 3: 
        return "рубля";
      case 4: 
        return "рубля";
      case 5: 
        return "рублей";
      case 6: 
        return "рублей";
      case 7: 
        return "рублей";
      case 8: 
        return "рублей";
      case 9: 
        return "рублей";
      case 10: 
        return "рублей";

      default: std::quick_exit(0);
    }

    throw "Что-то пошло не так.";
}

bool is_password(int password) {return password < 100000 ? 0 : 434;}



int main(void)
{
  std::string login;
  int password;
  std::vector<std::string> history;
  int balance{};
  int op{};

  char input;
  do
  {
    std::cout << "Вы хотите войти в свой личный кабинет банка? (y/n): ";
    std::cin >> input;
    if(input == 'y')
    {
      break;
    }
    else if(input == 'n')
    {
      std::puts("Вход отменен.");
      std::quick_exit(0);
    }
    else
    {
      std::puts("Введено что-то не то! Попробуйте заново.");
    }
  } while(input != 'y' || input != 'n');


    
  std::cout << "Придумайте логин:\n";
  std::cout << "--> ";
  std::cin >> login;


  std::puts("Придумайте цифровой пин-код для входа: ");
  do
  {
    std::cout << "--> ";
    std::cin >> password;
    if(!is_password(password))
    {
      std::puts("Пин-код должен состоять не менее, чем из 6 целых цифр.");
    }
    else if(is_password(password))
    {
      break;
    }
    else
    {
      std::puts("Попробуйте еще раз");
    }
  } while(true);
  
  system("clear"); 
  std::string my_login;
  std::cout << "Введите ваш логин: ";
  do
  {
    std::cout << "--> ";
    std::cin >> my_login;
    if(my_login != login)
    {
      std::puts("Логин введен неправильно.");
      std::puts("\nПовторите попытку: ");
    }
  } while (login != my_login);


  int is_try(5);

  
  std::cout << "Введите пин-код: ";
  do
  {
    int my_pass;
    std::cin >> my_pass;
    if(my_pass == password)break;
    else
    {
      std::puts("Пин-код неверный!");
      std::cout << "Осталось " << is_try << " попыток.\n\n";
      --is_try;
    }
    if(is_try == 0) 
    {
      std::puts("Лимит попыток исчерпан. \nВсех благ.");
    }
    std::cout << "Введите пин-код: ";
  }while(true);
    
  std::system("clear");
  std::cout << "---------------------Вы вошли в личный кабинет---------------------\n";

  std::cout << "На данный момент, общая сумма вашего баланса равна нулю." << std::endl;
  
  
  do 
  {
    std::puts("Введите цифру, которая находится перед той операцией, которую вам нужно выполнить -->");  
    std::cout << "|  " << "0) Пополнить баланс.\t\t\t" << "|\n";
    std::cout << "|  " << "1) Снять деньги.\t\t\t" << "|\n";
    std::cout << "|  " <<"2) Показать баланс.\t\t\t"<< "|\n";
    std::cout << "|  " << "3) Выйти (данные не сохраняться).\t" << "|\n";
    std::cout << "|  " << "4) Показать историю операций. \t" << "|\n";
    std::cout << "|  " << "5) Очистить историю. \t\t" << "|\n";
    std::cout << "--> ";

    std::cin >> op;

    if(op == 0)
    {
         
      std::string str = "Пополнение баланса.";
      addHistory(history, str);
          
      std::cout << "Сколько желаете пополнить?: ";
      int sum; std::cin >> sum;
      int b = plus_plus_balance(balance, sum); 
      balance = b;
           
      __try
      {
        std::string rub = correct(sum);
        if(rub == "рублей")
        {std::cout << "Пополнено " << sum << ' ' << rub << '.' << std::endl;}
        if(rub == "рубля")
        {std::cout << "Пополнено " << sum << ' ' << rub << '.' << std::endl;}
        if(rub == "рубль")
        {std::cout << "Пополнен " << sum << ' ' << rub << '.' << std::endl;}
        rub = correct(balance);
        std::cout << "Ваш баланс составляет " << balance << ' ' << rub << ".\n\n";
      }
        __catch(CorrectRub& e)
        {
          std::cout << e.what() << std::endl;
        }
    }
    else if(op == 1)
    {
           
            
      std::string str = "Снятие денег.";
      addHistory(history, str);
            
      std::cout << "Сколько желаете снять?: ";
      int sum; std::cin >> sum;
      int b = minus_minus_balance(balance, sum);
      if(b != -1)
      {
        balance = b;
        __try
        {
          std::string rub = correct(sum);
          std::cout << sum << " " << rub << " снято!" << std::endl;
          rub = correct(balance);
          std::cout << "Ваш баланс составляет " << balance << ' ' << rub << '.' << std::endl << std::endl;
        }
        __catch(CorrectRub& e)
        {
          std::cout << e.what() << std::endl;
        }
               
      }
      else 
      {
        std::puts("У вас недостаточно средств.");
        __try
        {
          std::string rub = correct(balance);
          std::cout << "Ваш баланс составляет " << balance << ' ' << rub << '.' << std::endl << std::endl;
        }
        __catch(CorrectRub& e)
        {
          std::cout << e.what() << std::endl;
        }
      }
    }
    else if(op == 2)
    {
      std::string str = "Вывод баланса на экран.";
      addHistory(history, str);
        
      __try
      {
        std::string rub = correct(balance);
        std::cout << "Ваш баланс составляет " << balance << ' ' << rub << '.' << std::endl;
      }
      __catch(CorrectRub& e)
      {
        std::cout << e.what() << std::endl;
      }
    }
    else if(op == 3)
    {
      break;
    }
    else if(op == 4)
    {
      if(history.empty())
      {
        std::puts("История пуста.");
      }
      else
      {
        showHistory(history);
      }
      std::string str = "Просмотр истории.";
      addHistory(history, str);
    }
    else if(op == 5)
    {
      if(history.empty())
      {
        std::puts("История итак пуста.");
      }
      else
      {
        history.clear();
        std::puts("История очищена.");
      }
    }
    else 
    {
      std::puts("Вам необходимо ввести именно те цифры, которые указаны, не более!");
    }
       
    int yes_no{};
    char x; 
    do
    {
      std::cout << "Хотите совершить еще операции? (y/n): ";
      std::cin >> x;
      if(x == 'n')
      {
        puts("Вы желаете выйти из личного кабинета (данные не сохраняться)? (y/n): ");
        std::cin >> input;
        if(input == 'y')
        {
          puts("\n\n---------------------Вы вышли с личного кабинета---------------------");
          std::quick_exit(0);
        }
      }   
         
    } while(x != 'y');
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::system("clear");
  } while(true);
  std::puts("\n---------------------Вы вышли из личного кабинета---------------------");
  return 0;
}