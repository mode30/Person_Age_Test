# Person Records Management System

## Overview
This C program provides a simple console-based interface for managing person records with two access modes:
- **Admin Mode**: Allows adding new person records (name and age) and saving them to a file
- **Guest Mode**: Basic access (currently just displays a greeting)

## Features
- Secure admin login with password protection(Not completely secure,password in file,future plan is to read from a txt with read only access on the admin side)
- Ability to add person records (name and age)
- Data persistence by saving records to "record.txt"
- Memory-safe implementation with proper allocation/deallocation
- Input validation and error handling

## Requirements
- C compiler (gcc, clang, etc.)
- Standard C library

## Compilation
Compile the program using:
```
gcc program.c -o person_records
```

## Usage
1. Run the compiled program:
   ```
   ./person_records
   ```

2. Select mode at startup:
   - `1` for Admin Mode
   - `2` for Guest Mode

### Admin Mode
- Enter admin name (any name)
- Password: "Pass" (case-sensitive)
- After login, you can:
  - Add new person records (option 1)
    - Enter name and age
    - Choose whether to save to file
  - Delete records (option 2 - not fully implemented)

### Guest Mode
Currently displays a greeting message (basic functionality)

## File Format
Records are saved to "record.txt" in tab-separated format:
```
Name    Age
John    25
Alice   30
```

## Notes
- The program limits the number of person records to 3 (configurable via `PERSON_SIZE`)
- Admin password is hardcoded as "Pass" (in a real application, this should be secured properly)
- The file is opened in append mode, so new records are added to the end of existing file

## Safety Features
- Memory is properly allocated and freed
- Input buffers are protected against overflow
- Basic error checking for file operations

## Limitations
- No search functionality implemented
- Delete operation is not fully implemented
- No encryption for stored data
- Password is hardcoded (not secure for production use)

## Future Improvements
- Add search functionality
- Implement proper delete operation
- Add record editing capability
- Implement proper user authentication system
- Add encryption for sensitive data
