import book
import user
import library
import gui
# GUI Implementation


# Initialize System
lib = library.Library()
book1 = book.Book("1984", "George Orwell", 3)
book2 = book.Book("Brave New World", "Aldous Huxley", 2)
user1 = user.User("Alice", "123 Library St")

lib.add_book(book1)
lib.add_book(book2)
lib.add_user(user1)

# Run GUI
root = gui.tk.Tk()
app = gui.GUI(root, lib)
root.mainloop()
