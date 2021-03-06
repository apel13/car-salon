# car-salon

**Car-salon** - console application that emulates the work of a car salon

### application requirements (in Russian):
1) Реализовать автоматическую генерацию каталога автомобилей (не более 10 штук), каждый из которых обладает ID и несколькими произвольными параметрами (например: цвет, цена, скорость).
2) Реализовать сущность покупателя, с атрибутом, который указывает на то, что он владеет конкретным автомобилем. По умолчанию, у покупателя нет автомобиля.
3) Реализовать возможность выбора фильтрации списка автомобилей по каждому произвольному параметру. Результатом фильтрации должна быть выборка автомобилей, по произвольному условию для конкретного параметра, выбранного через консоль (например: фильтрация по цене, которая принимает определенное число, и выбирает только автомобили с ценой ниже этого числа).
4) Реализовать возможность отображения отфильтрованного списка автомобилей.
5) Реализовать метод, позволяющий покупателю приобрести автомобиль из списка по ID, введенному через консоль. При покупке выбранный автомобиль пропадает из каталога.
6) Реализовать метод, показывающий, каким автомобилем владеет покупатель.
7) Реализовать основной цикл программы, в котором пользователь может:  
    - Вызвать help, который показывает доступные методы;  
    - Отобразить список авто;  
    - Отобразить отфильтрованный список авто (№3);  
    - Отобразить каким автомобилем владеет покупатель;  
    - Купить определенный автомобиль по ID;  
    - Выйти из программы.  

   
### Supported commands:
- **car_list**                     - show the list of cars  
- **filter_list**                    - show the filtered list of cars  
- **filter *[field]* *[op]* *[val]***      - filter the current list  
  *[field]* - `name`, `color`, `price`, `max_speed` or `weight`  
  *[op]*  - `<`,`>`,`==`,`!=`,`<=` or `>=`  
  *[val]*  - some value (string for `name` and `color`, and double for others)   
  example: `filter max_speed >= 300`
- **reset_filters**                  - reset all filters  
- **my_car**                         - show which car you own  
- **buy *[ID]***                       - buy a specific car by ID  
- **help**                           - show current help  
- **exit**                           - exit the program  


