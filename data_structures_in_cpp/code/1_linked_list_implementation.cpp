#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Node{

    int data;
    std::unique_ptr<Node> next_node;

    Node(int input_data){
        data = input_data;
        next_node = nullptr;
    }

    ~Node(){
        cout << "Node object destroyed\n";
    }
};

struct LinkedList{

    std::unique_ptr<Node> head; 

    LinkedList(){
        head = nullptr;
    }

    ~LinkedList(){
        cout << "LinkedList object destroyed\n";
    }

    void add_element_to_beginning(int value_to_add){

        unique_ptr<Node> temp = make_unique<Node>(value_to_add);

        if(head){
            temp->next_node = move(head);
            head = move(temp);
        } else {
            head = move(temp);
        }

        print_linked_list();
    }

    void add_element_to_tail(int value_to_add){
        
        if(head){
            Node* temp;

            for(temp = head.get(); temp->next_node != nullptr; temp = temp->next_node.get());

            temp->next_node = make_unique<Node>(value_to_add);            
            
        } else {
            head = make_unique<Node>(value_to_add);
        }

        print_linked_list();
    }

    void remove_element_at_head(){     
        
        /* Try to remove element at head iff there is atleast 1 element in head. */
        if(head){

            Node* prev_temp; Node* temp;

            temp = head.get();

            /* Determine if there is only one element in the list or there are more elements. */

            if(temp->next_node){

                head = move(head->next_node);

            } else {
                /* There is only one element. Hence, simply deallocate head and move on.*/

                head.reset();
            }
        }

        print_linked_list();
    }

    void remove_element_at_tail(){
        
        /* Check list not empty. */
        if(head){
            /* Check if list has more than one element */

            if(head->next_node){

                /* List has more than one element. */

                Node* temp = head.get();
                Node *prev_temp;
                
                while(temp->next_node){
                    prev_temp = temp;
                    temp = temp->next_node.get();
                }

                prev_temp->next_node.reset();                

            } else {
                /* There is only one element. Hence, simply deallocate head and move on.*/

                head.reset();
            }
        }

        print_linked_list();
    }

    void print_linked_list(){

        cout << "#####################################################################################\n";

        for(const Node* temp = head.get(); temp != nullptr; temp = temp->next_node.get()){
            cout << "Node address: " << temp << endl;
            cout << "Data: " << temp->data << endl;
            cout <<"Next: " << temp->next_node.get() << endl << endl << endl;
        }
    }

};

int main(){

    LinkedList linked_list_obj;

    linked_list_obj.add_element_to_beginning(1);
    linked_list_obj.add_element_to_tail(2);
    linked_list_obj.add_element_to_tail(3);

    linked_list_obj.remove_element_at_head();

    linked_list_obj.remove_element_at_tail();


	return 0;
}