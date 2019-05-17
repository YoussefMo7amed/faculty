///Implemented by: Youssef Mohamed
/// faculty of science - Alexandria University
// https://github.com/YoussefMo7amed
// https://codeforces.com/profile/YoussefMo7amed
// thanks for (mycodeschool) Channel on Youtube, GeeeksforGeeks site

// my includes
	//c & c++
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
	//Math
#include <math.h>
#include <cmath>
	//STL
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

/// namespaces

using namespace std;

/// my typedefs
typedef char type;
typedef int typei;

///structures
typedef struct btree
{
    type data ;
    btree* left;
    btree* right;
}btree;

//pointer to tree root
typedef btree* treeptr;

/// heads
		//mine
void YoussefMo7amed();
		//Basics
btree* new_node(type data);
btree* insert (btree* root,type data); // binary insertion
btree* delete_node(btree* root,type data);
		//searching
btree* max_node(btree* root);
btree* min_node(btree* root);
int hight (btree* root);
int number_of_nodes(btree* root);
		//print using nodes
void preorder (btree * root);
void inorder(btree* root );
void postorder (btree * root);
		//expresion tree
btree* expression(string s);
double calculator_double(string c);
int calculator_int(string c);
		//tools and handling some Errors
bool Operator(char c);
string removeSpaces(string str);
bool incorrect_exp(string s);
bool div_zero(string s);
string inTopost(string s);
bool heigher_priority(char c, char cc);
bool not_allowed(string s);
bool mod(string s);
bool is_opened_prant(char c);
bool is_closed_prant(char c);
bool prant_numbers(string s);
bool operand(char c);
//To the user (messages)
void msg1();
void msg2();
void tree_exps(btree* root);
void choice (btree* root,string str);
void properties(btree* tree,string s);
/// main

int main()
{
    // this function just to speed the code
    void YoussefMo7amed();

    btree* tree;
    tree = NULL;
    msg1();
    string str;
    getline (cin, str);
    str = removeSpaces(str);

    if((incorrect_exp(str)) || (div_zero(str)) || not_allowed(str))
    {
    	if(div_zero(str))
    	{
    		cout << "MATH ERROR: Can't Divide by Zero\n";
    	}
    	else
    	{
			cout << "please Enter the Expression correctly!\n\n";
    	}
        cout << "--------------------------------------------------------\n";
    	main();
    }
    else
    {
        str = inTopost(str);
    	tree = expression(str);
    	double n;
    	if(mod(str))
        {
            n = calculator_int(str);
        }
        else
        {
            n = calculator_double(str);
        }
		tree_exps(tree);
		cout << "the result is: " << n;
        cout << "\n--------------------------------------------------------\n";
        msg2();
        choice(tree,str);
    }
    return 0;
}

/// functions

void YoussefMo7amed()
{
    ios::sync_with_stdio(0); cin.tie(0);
}

btree* new_node(type data)
{
	btree* node = new btree();
	if(node== NULL)
    {
        cout << "Out of space!!";
        return NULL;
    }
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

btree* insert (btree* root,type data)
{
	if(root == NULL)
	{
		root = new_node(data);
	}
	else if(data < root->data)
	{
		root->left = insert(root->left,data);
	}
	else if(data >= root->data)
	{
		root->right = insert(root->right,data);
	}
	return root;
}

btree* delete_node(btree* root,type data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data < root->data)
	{
		root->left = delete_node(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = delete_node(root->right, data);
	}
	else
	{
		// leaf node
		if((root->left == NULL) && (root->right == NULL))
		{
			delete root;
			root = NULL;
		}
		// 1 child
		else if(root->left ==NULL)
		{
			btree* tmp;
			tmp = root;
			root = root->right;
			delete tmp;
		}
		else if(root->right == NULL)
		{
			btree* tmp;
			tmp = root;
			root = root->left;
			delete tmp;
		}
		// 2 children
		else
		{
			btree *tmp;
			tmp = min_node(root->right);
			root->data = tmp->data;
			root->right= delete_node(root->right, tmp->data);
		}
	}
	return root;
}

btree* max_node(btree* root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		btree* tmp;
		tmp = root;
		while(tmp->right!=NULL)
		{
			tmp= tmp->right;
		}
		return tmp;
	}
}

btree* min_node(btree* root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		btree* tmp;
		tmp = root;
		while(tmp->left!=NULL)
		{
			tmp= tmp->left;
		}
		return tmp;
	}
}

int hight (btree* root)
{
    if(root==NULL) return -1;
    return max(hight(root->left),hight(root->right))+1;
}

int number_of_nodes(btree* root)
{
    if(root== NULL) return 0;
    if(root->right == NULL && root->left ==NULL)return 1;
    return (number_of_nodes(root->left)+number_of_nodes(root->right))+1 ;
}
void preorder (btree * root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(btree* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder (btree * root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}

bool Operator(char c)
{
	return(c=='-' || c=='*'|| c=='/'|| c=='+'|| c=='^'|| c=='%');
}

btree* expression(string s)
{
	stack <btree*> st;
	btree* node;
	unsigned int n = s.length();
	// 	a+b-e*f*g -----  ab+ef*g*-
	for(unsigned int i=0;i< n;i++)
	{
		if(Operator(s[i]))
		{
			node = new_node(s[i]);
			node->right = st.top(); st.pop();
			node->left = st.top(); st.pop();
			st.push(node);
		}
		else
		{
			node = new_node(s[i]);
			st.push(node);
		}
	}
	node = st.top();
	st.pop();
	return node;
}

double calculator_double(string c)
{
	int n = c.length();
	stack <double> s;
	for(int i =0;i<n;i++)
	{
		if(isdigit(c[i]))
		{
			s.push(c[i]-'0');
		}
		else
		{
			double op1;
			op1 = s.top(); s.pop();
			double op2;
			op2 = s.top(); s.pop();
			switch(c[i])
			{
				case '+': s.push(op2 + op1) ; break;
				case '-': s.push(op2 - op1) ; break;
				case '*': s.push(op2 * op1) ; break;
				case '/': s.push(op2 / op1)	; break;
				case '^': s.push(pow(op2,op1)); break;
				//case '%': s.push(op2%op1); break; // it works if you want to Enter int not double nor float
			}
		}
	}
	double x = s.top();
	s.pop();
	return x;
}

int calculator_int(string c)
{
	int n = c.length();
	stack <int> s;
	for(int i =0;i<n;i++)
	{
		if(isdigit(c[i]))
		{
			s.push(c[i]-'0');
		}
		else
		{
			int op1;
			op1 = s.top(); s.pop();
			int op2;
			op2 = s.top(); s.pop();
			switch(c[i])
			{
				case '+': s.push(op2 + op1) ; break;
				case '-': s.push(op2 - op1) ; break;
				case '*': s.push(op2 * op1) ; break;
				case '/': s.push(op2 / op1)	; break;
				case '^': s.push(pow(op2,op1)); break;
				case '%': s.push(op2%op1); break; // it works if you want to Enter int not double nor float
			}
		}
	}
	int x = s.top();
	s.pop();
	return x;
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

bool incorrect_exp(string s)
{
	int d=0,op=0;
	unsigned n = s.length();
	for(unsigned int i=0;i<n;i++)
	{
		if(Operator(s[i]))
		{
			op++;
		}
		else
		{
			if(!is_opened_prant(s[i]) && !is_closed_prant(s[i]) )
			d++;
		}
	}
	if(!prant_numbers(s))
	{
		return 1;
	}
	return( (d>=op+2)|| (d<=op));
}

bool not_allowed(string s)
{
	unsigned int nn= s.length();
		for(unsigned int i=0;i<nn;i++)
	    {
	        if((s[i]>= 58 || s[i] < 40) && (!Operator(s[i])) && (s[i]!='[' || s[i]!='{' || s[i]!='}' || s[i]!=']'))
	        	return true;
	    }
		return false;
}
bool div_zero(string s)
{
	return(s.find("/0") != std::string::npos) || (s.find("%0") != std::string::npos);
}

string inTopost(string s)
{
    string res="";
    stack<char> st;
    unsigned int n = s.length();
    for(unsigned int i =0; i<n;i++)
    {

        if(Operator(s[i]))
        {
            while(!st.empty() && heigher_priority(st.top(),s[i]) && !is_opened_prant(st.top()))
            {
                res+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(operand(s[i]))
        {
            res+=s[i];
        }
        else if (is_opened_prant(s[i]))
        {
        	st.push(s[i]);
        }
        else if (is_closed_prant(s[i]))
        {
        	while(!s.empty() && !is_opened_prant(st.top()))
        	{
        		res+= st.top();
        		st.pop();
        	}
        	st.pop();
        }
    }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
    return res;
}

bool heigher_priority(char c, char cc)
{
    int d,dd;
    switch(c)
    {
        case '^': d=5; break;
        case '%': d=4; break;
        case '*' || '/': d=3; break;
        case '+': d=2; break;
        case '-': d=1; break;
    }
    switch(cc)
    {
        case '^': dd=5; break;
        case '%': dd=4; break;
        case '*' || '/': dd=3; break;
        case '+': dd=2; break;
        case '-': dd=1; break;
    }
    return (d>dd);
}
void msg1()
{
	cout  << "Expression Tree (Version 2) \nPlease Enter the Expression (inorder Expression)\non 1 line!\n";
}
void msg2()
{
	cout << "if you want to see the tree properties\n"
			<< "(yes/1):\t\tto see the properties"  << "\n(no/0) or (stop):\tto stop the program \n"
			<< "(other):\t\tto enter another expression!\n";
}
void tree_exps(btree* root)
{
	cout << "--------------------------------------------------------";
	cout << "\nthe pre-order  expression is :<   ";
		preorder(root); cout << "   >";
	cout << "\nthe in-order   expression is :<   ";
		inorder(root); cout << "   >";
	cout << "\nthe post-order expression is :<   ";
		postorder(root); cout << "   >";
	cout <<"\n";
	cout << "--------------------------------------------------------\n";
}

void choice (btree* root,string str)
{
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s = removeSpaces(s);
        while (s!= "no" || s!= "0" ||s != "stop")
        {
            if(s== "yes" || s=="1" || str[0]=='y')
    		{
    		    properties(root,str);
    		    break;
    		}
            else if (s== "other")
            {
            	main();
            	break;
            }
            else if (s!= "no" || s!= "0" ||s != "stop")
            {
            	cout << "thank you!\n";
            	break;
            }
            else
            {
            	cout << "\n--------------------------------------------------------\n";
            	cout << "\nplease Enter an operation correctly!\n";
            	cout << "\n--------------------------------------------------------\n";
            	choice(root,str);
            }
        }
}
void properties(btree* tree,string s)
{
	int depth = hight(tree);
	//char min_node =*  min_node(tree);
	int n = number_of_nodes(tree);
	char mx = s[0];
	char mn = s[0];
	unsigned int nn= s.length();
	for(unsigned int i=1;i<nn;i++)
    {
        if(!Operator(s[i]))
        {
            mn = min(s[i],mn);
            mx = max(s[i],mx);
        }
    }
	cout << "\nNumber of nodes in the tree is:\t" << n << "\n";
	cout << "the tree depth is:\t" << depth << "\n";
	cout << "the maximum value is:\t" << mx << "\n";
	cout << "the minimum value is:\t" << mn;
}

bool mod(string s)
{
    unsigned int n = s.length();
    for(unsigned int i=0;i<n;i++)
    {
        if(s[i]=='%')
            return  1;
    }
    return 0;
}

bool is_opened_prant(char c)
{
	return c == '(' || c == '{' ||  c == '[';
}
bool is_closed_prant(char c)
{
	return c == ')' ||  c == '}' ||  c == ']';
}

bool prant_numbers(string s)
{
	int opened =0 , closed =0;
	unsigned int n = s.length();
	for(unsigned int i = 0; i<n;i++)
	{
		if(is_opened_prant(s[i]))
			opened++;
		if(is_closed_prant(s[i]))
			closed++;
	}
	return opened == closed;
}

bool operand(char c)
{
	return c>='0' && c<='z';
}
