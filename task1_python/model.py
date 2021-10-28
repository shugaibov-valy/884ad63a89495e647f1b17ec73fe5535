import sqlalchemy as sq
from db import Base, session

class List_DataBase(Base):
    __tablename__: str = 'list_db'
    id = sq.Column(sq.Integer, primary_key=True)
    name = sq.Column(sq.String)

    @classmethod
    def add_new_row(cls, new_index=None, text=None):
        last_index = session.query(cls).count()
        if last_index != 0:
            last_index -= 1
        if new_index > 0 and new_index > last_index or\
                          new_index == 0 and new_index == last_index:
            new_row = List_DataBase()
            new_row.name = text
            session.add(new_row)
            session.commit()

        elif new_index == -1:
            all = [el.name for el in session.query(cls).all()]
            all.insert(0, (text))
            session.query(cls).delete()
            session.commit()
           
            for i in all:
                new_row = List_DataBase()
                new_row.name = i
                session.add(new_row)
                session.commit()

    @classmethod
    def get_index(cls, text=None):
        all = [el.name for el in session.query(cls).all()]
        try:
            return all.index(text) 
        except:
            print("Индекс не найден!")

    @classmethod
    def get_elem(cls, index=None):
        all = [el.name for el in session.query(cls).all()]
        try:
            return all[index]
        except:
            print("Индекс не найден!")
    
    @classmethod
    def del_elem(cls, index=None):
        all = [[el.id, el.name] for el in session.query(cls).all()]
        try:
            id_elem = all[index][0]
            elem = session.query(cls).filter_by(id=id_elem).first()
            session.delete(elem)
            session.commit()
        except:
            print("Индекс для удаления не найден!")
