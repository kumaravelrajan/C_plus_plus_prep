#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Node{

    int data;
    std::unique_ptr<Node> next_node;

    Node(int input_data){
        data = input_data;
    }
};

void print_linked_list(const Node* head_of_linked_list){

    int position_in_linked_list = 0;
    
    for(const Node* temp = head_of_linked_list; temp != NULL; temp = temp->next_node.get()){
        cout << "Address of node: " << temp << endl;
        cout << "linked_list[" << position_in_linked_list << "].data = " << temp->data << endl;
        cout << "linked_list[" << position_in_linked_list << "].next = " << temp->next_node.get() << endl << endl << endl;

        position_in_linked_list++;
    }

}

int main(){

    Node linked_list_head(4);

    linked_list_head.next_node = std::make_unique<Node>(5);;



    print_linked_list(&linked_list_head);


	return 0;
}