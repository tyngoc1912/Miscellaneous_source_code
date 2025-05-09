import tkinter as tk
from tkinter import messagebox
import library
import book
import user

class GUI:
    def __init__(self, root, library):
        self.library = library
        self.root = root
        self.root.title("Library Management System")
        
        self.label = tk.Label(root, text="Library Management", font=("Arial", 16))
        self.label.pack()
        
        self.book_list = tk.Listbox(root, width=50)
        self.book_list.pack()
        self.update_book_list()
        
        self.borrow_button = tk.Button(root, text="Borrow Book", command=self.borrow_book)
        self.borrow_button.pack()
        
        self.return_button = tk.Button(root, text="Return Book", command=self.return_book)
        self.return_button.pack()
        
        self.refresh_button = tk.Button(root, text="Refresh", command=self.update_book_list)
        self.refresh_button.pack()
    
    def update_book_list(self):
        self.book_list.delete(0, tk.END)
        for book in self.library.display_books():
            self.book_list.insert(tk.END, book)
    
    def borrow_book(self):
        selected = self.book_list.curselection()
        if selected:
            book_title = self.book_list.get(selected[0]).split(" by ")[0]
            message = self.library.borrow_book(user1, book_title)
            messagebox.showinfo("Borrow Book", message)
            self.update_book_list()
        else:
            messagebox.showwarning("Warning", "Please select a book to borrow.")
    
    def return_book(self):
        selected = self.book_list.curselection()
        if selected:
            book_title = self.book_list.get(selected[0]).split(" by ")[0]
            message = self.library.return_book(user1, book_title)
            messagebox.showinfo("Return Book", message)
            self.update_book_list()
        else:
            messagebox.showwarning("Warning", "Please select a book to return.")