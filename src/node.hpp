#ifndef _NODE_H_
#define _NODE_H_

class Node {
private:
	int x, y;
	int level;
	int cost;
	double costD;
	Node *dad;
	
public:
	Node(int x, int y, int cost, Node* dad);
	Node(int x, int y, int cost, double costD, Node* dad);
	Node(int x, int y, int cost, int Level, Node* dad);
	Node();

	int getX();
	int getY();
	int getcost();
	int getLevel();
	double getcostD();
	Node* getDad();
	void setX(int x);
	void setY(int y);
	void setLevel(int Level);
	void setcost(int cost);
	void setcostD(double cost);
	void setDad(Node *dad);
};

#endif
