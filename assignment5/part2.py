from abc import ABC, abstractmethod


  # Abstract Subject class
class Subject(ABC):
      def __init__(self):
          self._observers = []

      def add_observer(self, observer):
          if observer not in self._observers:
              self._observers.append(observer)

      def remove_observer(self, observer):
          self._observers.remove(observer)

      def notify_observers(self):
          for observer in self._observers:
              observer.update(self)


  # Abstract Observer class
class Observer(ABC):
      @abstractmethod
      def update(self, subject):
          pass

class ConcreteSubject(Subject):
      def __init__(self):
          super().__init__()
          self._items = {}

      def set_item(self, key, value):
          self._items[key] = value
          self.notify_observers()

      def get_items(self):
          return self._items


  # ConcreteObserver class
class ConcreteObserver(Observer):
      def __init__(self, name):
          self._name = name

      def update(self, subject):
          items = subject.get_items()
          print(f"Observer {self._name}: Dictionary updated - {items}")


  # Main program
if __name__ == "__main__":
      # Create a ConcreteSubject object
      subject = ConcreteSubject()

      # Create ConcreteObservers
      observer1 = ConcreteObserver("Observer 1")
      observer2 = ConcreteObserver("Observer 2")

      # Add observers to the subject
      subject.add_observer(observer1)
      subject.add_observer(observer2)

      # Set initial items in the dictionary
      subject.set_item("key1", "value1")
      subject.set_item("key2", "value2")

      # Modify dictionary and observe changes
      subject.set_item("key1", "updated_value1")
      subject.set_item("key3", "new_value3")
