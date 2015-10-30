#include "node.hpp"

Node::Node() {}

Node::Node(int x, int y, int cost, Node* dad) {
	setX(x);
	setY(y);
	setcost(cost);
	setDad(dad);
}

Node::Node(int x, int y, int cost, double costD, Node* dad){
	setX(x);
	setY(y);
	setcost(cost);
	setcostD(costD);
	setDad(dad);
}

Node::Node(int x, int y, int cost, int level, Node* dad) {
	setX(x);
	setY(y);
	setcost(cost);
	setLevel(level);
	setDad(dad);
}

int Node::getLevel(){
	return this->level;
}

void Node::setLevel(int level) {
	this->level = level;
}

int Node::getX(){
	return this->x;
}

int Node::getY(){
	return this->y;
}

int Node::getcost(){
	return this->cost;
}

double Node::getcostD(){
	return this->costD;
}

Node* Node::getDad(){
	return this->dad;
}

void Node::setX(int x){
	this->x = x;
}

void Node::setY(int y){
	this->y = y;
}

void Node::setcost(int cost){
	this->cost = cost;
}

void Node::setcostD(double cost){
	this->costD = cost;
}

void Node::setDad(Node *dad){
	this->dad = dad;
}

