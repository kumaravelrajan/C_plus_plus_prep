#include <iostream>
#include <string>

using namespace std;

class User{

    /* Default status of class is private, so no one can access the secret. */
    int _secret = 22; 

    public:
    string name = "default";
    
    /* Example of separating class method declaration and definition. */
    void classMessage();

    /* 
    
        SETTERS
    
        We have two options :
    
        1. int & newSecret
        2. const int & newSecret

        const int & newSecret (Option 2) is needed because this enables us to pass temporary values or literals during function calls. Hence we can pass setSecret(333) and not face an error. const int & makes sure that we CANNOT modify the literal value using this newSecret reference. 

        int & newSecret on the other hand enables modifying the literal value which does not make much sense. Hence, this causes a compilation error. This option would be fine if we were passing variables during function call. Then, lvalue of this variable will be taken into the reference newSecret.
    */
    void setSecret(int & newSecret){
        cout << "Function called : void setSecret(int & newSecret)" << endl;
        _secret = newSecret;
    }

    void setSecret(const int & newSecret){
        cout << "Function called : void setSecret(const int & newSecret)" << endl;
        _secret = newSecret;
    }

    /* GETTERS */

    /* Meaning of const modifier in different positions in the member method definition
        1. int getSecret() const
        The const after the parameter list means this is a const-qualified member function.
        It promises not to modify any member variables (unless they're marked mutable) and can only call other const member functions.
        Used for methods that should not change the object.

        2. const int getSecret()
        The const before the return type means the returned value is const.
        For built-in types like int, this has no practical effect—the caller gets a copy and cannot modify the original anyway.
        More useful for returning references or pointers.
        
        3. int const getSecret()
        This is identical to const int getSecret(); in C++, int const and const int are the same.
        Again, for built-in types, returning a const value is not meaningful.
    */

    int getSecret() const {
        return _secret;
    }
};


/* Writing classMessage() method of User class outside class definition */

void User::classMessage(){
    cout << "Class is great, " << name << endl;
}

int main () {

    /* sam is called object of class User. */

    User sam; 

    sam.classMessage(); /* Class is great, default */
    sam.name = "Sam";
    sam.classMessage(); /* Class is great, Sam */

    /* Notice that setting getSecret() to const does not affect sam object. This is because non-const class objects can safely call const methods. BUT const objects CANNOT call non-const methods (because these might modify internal state.) */

    cout << "Initial secret value : " << sam.getSecret() << endl;
    
    sam.setSecret(333); /* Calls void setSecret(const int & newSecret) */

    cout << "sam.setSecret(333); : " << sam.getSecret() << endl;
    
    int sample = 5000;
    sam.setSecret(sample); /* Calls void setSecret(int & newSecret) */

    cout << "Value should be 5000 : " << sam.getSecret() << endl;

    /* ##################################################################################################### */

    /* 
    Once we declare an object of a class as const we CANNOT call non-const member functions and cannot modify ANY non-mutable member variables. 
    
    The purpose of having a const class object is that the object remains unchanged throughout its scope and retains the values given to it at the time of declaration (maybe by using constructors.)

    const objects can ONLY call const member functions. const member functions also cannot modify any member variables and can ONLY call other const member functions. This ensures that the internal state of a const object remains unchanged. 

    */

    const User constObject;

    cout << "constObject.getSecret() : " << constObject.getSecret() << endl;

	return 0;

}