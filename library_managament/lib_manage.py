class Book:
    def __init__(self, title, author, copies_available):
        self.title = title
        self.author = author
        self.copies_available = copies_available
    
    def check_book_borrow(self):
        if self.copies_available > 0:
            self.copies_available -= 1
            return True
        return False
    
    def display_info(self):
        return f"{self.title} by {self.author} - Copies Available: {self.copies_available}"

class User:
    def __init__(self, name, address):
        self.name = name
        self.address = address
        self.borrowed_books = []
    
    def borrow_book(self, book):
        if book.check_book_borrow():
            self.borrowed_books.append(book)
            return f"{self.name} borrowed {book.title}."
        else:
            return f"Sorry, {book.title} is not available."
    
    def return_book(self, book):
        if book in self.borrowed_books:
            book.copies_available += 1
            self.borrowed_books.remove(book)
            return f"{self.name} returned {book.title}."
        else:
            return f"{self.name} did not borrow {book.title}."
    
    def display_info(self):
        return f"{self.name} - {self.address}"
    
class Library:
    def __init__(self):
        self.books = []
        self.users = []
    
    def add_book(self, book):
        self.books.append(book)
    
    def add_user(self, user):
        self.users.append(user)
    
    def borrow_book(self, user, book_title):
        for book in self.books:
            if book.title == book_title:
                return user.borrow_book(book)
        return "Book not found."
    
    def return_book(self, user, book_title):
        for book in self.books:
            if book.title == book_title:
                return user.return_book(book)
        return "Book not found."

    def display_books(self):
        return [book.display_info() for book in self.books]
    
    def display_users(self):
        return [user.display_info() for user in self.users]