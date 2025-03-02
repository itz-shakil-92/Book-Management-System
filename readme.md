# Book Management System

## Description

The **Book Management System** is a simple C++ application that allows users to manage a collection of books using file handling. Users can add, delete, search, update, and display books stored in a binary file.

## Features

- Add a book with ID, title, and price
- Delete a book by title
- Search for a book by title
- Update book details by title
- View all books stored in the system

## Technologies Used

- C++
- File Handling (Binary Files)

## How to Run

1. Compile the program using a C++ compiler:
   ```bash
   g++ book_management_system.cpp -o book_management_system
   ```
2. Run the executable:
   ```bash
   ./book_management_system
   ```

## Usage

When you run the program, you will see a menu with the following options:

1. Add a Book
2. Delete a Book
3. Search a Book
4. Update a Book
5. Display all Books
6. Exit

Follow the prompts to perform the desired actions.

## File Storage

- Book records are stored in a binary file named `books.dat`.
- Temporary files (`temp.dat`) are used when deleting or updating records.

## Example Interaction

```
----------------------------Welcome to Our Book Management System--------------------------
---------------------------------------------------------------------------------------------

1. Add a Book
2. Delete a Book
3. Search a Book
4. Update a Book
5. Display all Books
6. Exit

your option is: 1
Enter bookId, title and price:
101
C++ Programming
500
Book Added Successfully
```

## Future Enhancements

- Implement a graphical user interface (GUI)
- Add sorting and filtering options for books
- Support exporting book details to a text or CSV file

## License

This project is open-source and available under the MIT License.

## Author

- **Shakil Kathat**

