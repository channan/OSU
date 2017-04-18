/**********************************************
 * Program Name: List.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Contains the main functions to run the program. An add item function that add items to the list using user inputted parameters. A remove item function that removes items from the list. A function to display the list to the user. As well as bool function containing the overloaded operator function for ==.
 **********************************************/

#include "List.hpp"

using std::cin;

void List::addItem(string n, string u, int q, double p) //adds items to the list
{
    Item item(n,u,q,p);
    if(this->operator==(item)) //checks if item is already in the list using overloaded operator
    {
        cout << "That item is already on the list." << endl << endl;
    }
    else
    {
        shoppingList[listSize]= new Item(n,u,q,p);
        listSize++;
    }
}
void List::removeItem(int location) //removes items from the list
{
    for(int i=location;i<listSize-1;i++)
    {
        shoppingList[i]=shoppingList[i+1]; //shifts listed items up to overwrite the item to be removed
    }
    listSize--;
    shoppingList[listSize]=new Item;
    if(listSize>3)
    {
        delete shoppingList[listSize]; //deletes last item in the list which is a duplicate after the shift
    }
}
void List::displayList() //display contents fo the list to the user
{
    double total=0;
    
    if(listSize<4)
    {
        for (int i=0;i<4;i++)
        {
            cout << i+1 << ".Name: " << shoppingList[i]->getName() << endl;
            cout << "  Unit: " << shoppingList[i]->getUnit() << endl;
            cout << "  Quantity: " << shoppingList[i]->getQuantity() << endl;
            cout << "  Price: $" << shoppingList[i]->getPrice() << endl;
            cout << "  Total Price: $" << shoppingList[i]->totalPrice() << endl << endl;
        }
    }
    if(listSize>3)
    {
        for(int i=0;i<listSize;i++)
        {
            cout << i+1 << ".Name: " << shoppingList[i]->getName() << endl;
            cout << "  Unit: " << shoppingList[i]->getUnit() << endl;
            cout << "  Quantity: " << shoppingList[i]->getQuantity() << endl;
            cout << "  Price: $" << shoppingList[i]->getPrice() << endl;
            cout << "  Total Price: $" << shoppingList[i]->totalPrice() << endl << endl;
        }
    }
    
    for(int i=0;i<listSize;i++)
    {
        total=total+shoppingList[i]->totalPrice();
    }
    cout << "Total price of shopping list: $" << total << endl << endl; //show overall price of the shopping list to the user
}
bool List::operator==(Item& obj) //overloaded operator == is used to compare objects in the list. returns a bool value
{
    for(int i=0;i<listSize;i++)
    {
        if((this->shoppingList[i])->getName()==obj.getName())
        {
            return true;
        }
    }
    return false;
}

