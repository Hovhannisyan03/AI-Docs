#include "DocumentManager.h"

void DocumentManager::menu()
{
    std::cout << "-------------------------" << std::endl;
    std::cout << "| FILE MANAGMENT SYSTEM |" << std::endl;
    std::cout << "-------------------------" << std::endl;
again:   
    std::cout << "----------------------" << std::endl;     
    std::cout << "| 1. Create Document |" << std::endl;
    std::cout << "| 2. Edit Document   |" << std::endl;
    std::cout << "| 3. View Document   |" << std::endl;
    std::cout << "| 4. Show Document   |" << std::endl;
    std::cout << "| 5. Exit            |" << std::endl;
    std::cout << "----------------------" << std::endl;     

    char choose;
    std::cout << "=== Enter your choose: ";
    std::cin >> choose;
    switch(choose)
        {
        case '1':
        {   
            createDocument();
            break;
        }
        case '2':
        {
            editDocument();
            break;
        }
        case '3':
        {
            viewDocument();
            break;
        }
        case '4':
        {
            showDocuments();
            break;
        }
        case '5':
        {
            std::cout << "-----------------------" << std::endl;
            std::cout << "| The program is over |" << std::endl;
            std::cout << "-----------------------" << std::endl;
            return;
        }
        default:
        {
            std::cout << "=== Invalid input ===" << std::endl;
        }
    }
    
    std::string ch;
    std::cout << "=== Continue file managment(Y/N): ";
    std::cin >> ch;
    if(ch == "Y" || ch == "y" || ch == "Yes" || ch == "YES" || ch == "yes")
    {
        goto again;
    }
    return;
}

void DocumentManager::createDocument()
{
    std::string fileName;
again: std::cout << "=== Enter file name: ";
    std::cin >> fileName;

    if(0 == allFiles.size())
    {
        allFiles.push_back(fileName);
        std::ofstream file(fileName);
        std::cout << "=== Documnet " << fileName << " created successfully ===" << std::endl;
        return;
    }
    
    for(auto elem : allFiles)
    {
        if(elem == fileName)
        {
            std::cout << "=== A file with that name already exists ===" << std::endl;
            goto again;
        }
    }

    allFiles.push_back(fileName);
    std::ofstream file(fileName);
    std::cout << "=== Document " << fileName << " created successfully ===" << std::endl;
    return;
}

void DocumentManager::editDocument()
{
    if(0 == allFiles.size())
    {
        std::cout << "=== Document list is empty ===" << std::endl;
        return;
    }
again:
    std::string fileName;
    std::fstream file;
    std::cout << "=== Enter file name: ";
    std::cin >> fileName;
    int count = 0;
    for(auto elem : allFiles)
    {
        if(elem == fileName)
        {
            ++count;
        again1:
            std::cout << "------------------------" << std::endl;
            std::cout << "| 1. Write new contents|" << std::endl;
            std::cout << "| 2. Append contents   |" << std::endl;
            std::cout << "------------------------" << std::endl;
            char choose;
            std::cout << "=== Enter your choose: ";
            std::cin >> choose;
            switch(choose)
            {
                case '1':
                {   
                    const size_t size = 100;
                    char arr[size];
                    std::cout << "=== Enter contents: ";
                    std::cin.get();
                    std::cin.getline(arr,size);
                    file.open(fileName, std::ios::out);
                    file << arr << std::endl;
                    file.close();
                    std::cout << "=== Content added to " << fileName << " ===" << std::endl;
                    break;
                }
                case '2':
                {
                    std::fstream file;
                    const size_t size = 100;
                    char arr[size];
                    std::cout << "=== Enter contents: ";
                    std::cin.get();
                    std::cin.getline(arr,size);
                    file.open(fileName, std::ios::app);
                    file << arr << std::endl;
                    file.close();
                    std::cout << "=== Content added to " << fileName << " ===" << std::endl;
                    break;
                }
                default:
                {
                    std::cout << "=== Invalid input ===" << std::endl;
                    goto again1;
                }
            }    
        }
    }
    if(count == 0)
    {
        std::cout << "=== Invalid file name ===" << std::endl;
        goto again;
    }
    std::string ch;
    std::cout << "=== Continue edit document(Y/N): ";
    std::cin >> ch;
    if(ch == "Y" || ch == "y" || ch == "Yes" || ch == "YES" || ch == "yes")
    {
        goto again;
    }
    return;
}

void DocumentManager::viewDocument()
{
    if(0 == allFiles.size())
    {
        std::cout << "=== Document list is empty ===" << std::endl;
        return;
    }
again:    
    std::string fileName;
    std::cout << "=== Enter file name: ";
    std::cin >> fileName;

    std::fstream file;
    for(auto elem : allFiles)
    {
        if(elem == fileName)
        {   
            file.open(fileName, std::ios::in);
            std::string line;
            std::cout << "=== File contents ===" << std::endl;
            while(getline(file, line))
            {
                std::cout << line;
            }
            file.close();
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "=== Invalid file name ===" << std::endl;
    std::string ch;
    std::cout << "=== Continue view document(Y/N): ";
    std::cin >> ch;
    if(ch == "Y" || ch == "y" || ch == "Yes" || ch == "YES" || ch == "yes")
    {
        goto again;
    }
    return;
}

void DocumentManager::showDocuments()
{
    if(0 == allFiles.size())
    {
        std::cout << "=== Document list is empty ===" << std::endl;
        return;
    }
    std::cout << "=== All documents ===" << std::endl;
    for(auto elem : allFiles)
    {
        std::cout << elem << std::endl;
    }
    return;
}