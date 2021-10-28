from db import Base, engine
from model import List_DataBase

### function for create table "list_db" class List_DataBase
def database_create():
    Base.metadata.drop_all(bind=engine, tables=[List_DataBase.__table__])
    Base.metadata.create_all(engine)
    return True


### function for add new row in table
def database_insert(index, value): 
    List_DataBase.add_new_row(index, value)

def database_read(index):
    return List_DataBase.get_elem(index)

def database_search(text):
    return List_DataBase.get_index(text)

def database_delete(index):
    List_DataBase.del_elem(index) 


db = database_create()
db = database_create() 
database_insert(0, "Big") 
database_insert(1, "Flame") 
database_insert(-1, "reat") 
value = database_read(1) 
print(value)     # выведет ‘Big’ 
index = database_search("Big") 
print(index)                                        # выведет 1 
database_delete(0)    # удалит ‘Hello’ элемент 
value = database_read(2)                         # должно вызвать ошибку 
value = database_read(0) 
#print(value)     # выведет ‘Big’
