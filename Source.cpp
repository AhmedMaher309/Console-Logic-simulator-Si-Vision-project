#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
private:
	string NodeId;
	bool flag;  // determine the value in the node(wire) 0 or 1

public:
	friend ostream& operator<<(ostream& out, const Node& dt);

	Node()
	{
		NodeId = "0";
		flag = 0;
	}

	Node(string c, bool val) :NodeId(c), flag(val) {
		//cout << "non default Node called" << endl;
	}

	void setNodeId(string NodeId) {
		this->NodeId = NodeId;
	}

	void setFlag(bool flag) {
		this->flag = flag;
	}

	string getNodeId()
	{
		return NodeId;
	}

	bool getFlag() {
		return flag;
	}

	bool AND(Node a, Node b) {
		bool out = 0;
		if (a.getFlag() == 1 && b.getFlag() == 1) {
			out = 1;
		}
		return out;
	}

	bool OR(Node a, Node b) {
		bool out = 1;
		if (a.getFlag() == 0 && b.getFlag() == 0) {
			out = 0;
		}
		return out;
	}

	bool XOR(Node a, Node b) {
		bool out = 1;
		if ((a.getFlag() == 1 && b.getFlag() == 1) || (a.getFlag() == 0 && b.getFlag() == 0)) {
			out = 0;
		}
		return out;
	}
};
ostream& operator<<(ostream& out, const Node& N)
{
	out << N.NodeId << ": " << N.flag << endl;
	return out;
}

////////////////////////////  GATES  ////////////////////////////

class Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:
	Gate() {
	}
	Gate(Node* a, Node* b, Node* c) :in_node1(a), in_node2(b), out_node(c) {

	}

	virtual void setNode1(bool in_node1) {

	}

	virtual void setNode2(bool in_node2) {

	}

	virtual void setOutNode(Node* node) {

	}

	virtual Node* getNode1() {
		return in_node1;
	}

	virtual Node* getNode2() {
		return in_node2;
	}

	virtual Node* getOutNode() {
		return out_node;
	}

	virtual void simulateGate() {
	}
};

class AND :public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:
	
	AND(Node* a, Node* b) :in_node1(a), in_node2(b) {

	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}

	void simulateGate()
	{
		if (in_node1->getFlag() == 1 && in_node2->getFlag() == 1) {
			out_node->setFlag(1);
		}
		else {
			out_node->setFlag(0);
		}
	}
};

class OR :public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:

	OR(Node* a, Node* b) : in_node1(a), in_node2(b) {

	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}

	void simulateGate()
	{
		if (in_node1->getFlag() == 0 && in_node2->getFlag() == 0) {
			out_node->setFlag(0);
		}
		else {
			out_node->setFlag(1);
		}
	}
};

class XOR : public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:
	

	XOR(Node* a, Node* b) :in_node1(a), in_node2(b) {
		
	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}
	void simulateGate()
	{
		if ((in_node1->getFlag() == 0 && in_node2->getFlag() == 0) || (in_node1->getFlag() == 1 && in_node2->getFlag() == 1)) {
			out_node->setFlag(0);
		}
		else {
			out_node->setFlag(1);
		}
	}

};

class NAND : public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:
	
	NAND(Node* a, Node* b) :in_node1(a), in_node2(b) {
		
	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}
	void simulateGate()
	{
		if (in_node1->getFlag() == 1 && in_node2->getFlag() == 1) {
			out_node->setFlag(0);
		}
		else {
			out_node->setFlag(1);
		}
	}

};

class XNOR : public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:
	

	XNOR(Node* a, Node* b) :in_node1(a), in_node2(b) {
	
	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}
	void simulateGate()
	{
		if ((in_node1->getFlag() == 0 && in_node2->getFlag() == 0) || (in_node1->getFlag() == 1 && in_node2->getFlag() == 1)) {
			out_node->setFlag(1);
		}
		else {
			out_node->setFlag(0);
		}
	}


};

class NOT : public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:
	NOT(Node* a, Node* b) :in_node1(a), in_node2(b) {
	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}
	void simulateGate()
	{
		out_node->setFlag(!in_node1->getFlag());
	}

};

class NOR : public Gate {
private:
	Node* in_node1;
	Node* in_node2;
	Node* out_node;

public:

	NOR(Node* a, Node* b) :in_node1(a), in_node2(b) {
	
	}
	void setNode1(bool in_node1) {
		this->in_node1->setFlag(in_node1);
	}

	void setNode2(bool in_node2) {
		this->in_node2->setFlag(in_node2);
	}

	void setOutNode(Node* out_node) {
		this->out_node = out_node;
	}

	Node* getNode1() {
		return in_node1;
	}

	Node* getNode2() {
		return in_node2;
	}

	Node* getOutNode() {
		return out_node;
	}

	void simulateGate()
	{
		if (in_node1->getFlag() == 0 && in_node2->getFlag() == 0) {
			out_node->setFlag(1);
		}
		else {
			out_node->setFlag(0);
		}
	}
};

//////////////////////////  SIMULATOR  //////////////////////////

class simulator {
private:
	vector<Node*> nodeArr = {};
	vector<Gate*> gateArr = {};

public:

	void postGate(Gate* g) {
		gateArr.push_back(g);
	}

	void postNode(Node* n) {
		nodeArr.push_back(n);
	}

	Node* findNode(string node)
	{
		Node* ptr = nullptr;
		for (size_t i = 0; i < nodeArr.size(); i++) {
			if (nodeArr[i]->getNodeId() == node) {
				ptr = nodeArr[i];
			}
		}
		return ptr;
	}

	void startSimulate() {
		for (size_t i = 0; i < gateArr.size(); i++)
		{
			gateArr[i]->simulateGate();
		}
	}

	vector<Node*> getNodes() {
		return nodeArr;
	}

	vector<Gate*> getGates()
	{
		return gateArr;
	}

};

class GateGenerator {
private:
	queue<pair<string, bool>>q1;
	string dd;
	simulator sim;

public:
	
	void printPair(pair<string, bool> p)
	{
		string f = p.first;
		bool s = p.second;
		cout << f << ": " << s << endl;
	}
	
	void print() {
		while(!q1.empty())
		{
			printPair(q1.front());
			q1.pop();
		}
	}

	simulator getSim()
	{
		return sim;
	}
	
	void parseInput(string s) {
		if (s == "AND" || s == "OR" || s == "NOR" || s == "NAND" || s == "XOR" || s == "XNOR") {
			string a;
			cin >> a;
			if (!sim.findNode(a))
			{
				Node* N1 = createNode(a);
				sim.postNode(N1);
			}
			string b;
			cin >> b;
			if (!sim.findNode(b)) 
			{
				Node* N2 = createNode(b);
				sim.postNode(N2);
			}
			string c;
			cin >> c;
			if (!sim.findNode(c))
			{
				Node* N3 = createNode(c);
				sim.postNode(N3);
			}
			Gate* G = createGate(s, sim.findNode(a), sim.findNode(b));
			G->setOutNode(sim.findNode(c));
			sim.postGate(G);
		}
		else if (s == "NOT") {
			string a;
			cin >> a;
			if (!sim.findNode(a))
			{
				Node* N1 = createNode(a);
				sim.postNode(N1);
			}
			string b;
			cin >> b;
			if (!sim.findNode(b))
			{
				Node* N2 = createNode(b);
				sim.postNode(N2);
			}
			Gate* G = createGate(s, sim.findNode(a), sim.findNode(b));
			G->setOutNode(sim.findNode(b));
			sim.postGate(G);
		}
		else if (s == "SET") {
			string a;
			cin >> a;
			bool x;
			cin >> x;
			sim.findNode(a)->setFlag(x);
		}
		else if (s == "SIM") {
			sim.startSimulate();
		}
		else if (s == "OUT") {
			string s;
			cin >> s;
			if (s != "ALL")
			{
				//cout << s << ":" << sim.findNode(s)->getFlag() << endl;
				pair<string, bool>p1;
				p1.first = sim.findNode(s)->getNodeId();
				p1.second = sim.findNode(s)->getFlag();
				q1.push(p1);
			}
			else {
				for (size_t i = 0; i < sim.getNodes().size(); i++) {
					//cout << sim.getNodes()[i]->getNodeId() << ":" << sim.getNodes()[i]->getFlag() << endl;
					pair<string, bool>p1;
					p1.first = sim.getNodes()[i]->getNodeId();
					p1.second = sim.getNodes()[i]->getFlag();
					q1.push(p1);
				}
			}
		}
	}
	
	Node* createNode(string s) {
		Node* N = new Node(s, 0);
		return N;
	}

	Gate* createGate(string s, Node* x, Node* y)
	{
		//vector<string> gts = { "AND","OR","NOT","XOR","XNOR","NOR","NAND" };
		if (s == "AND") {
			// AND GATE
			AND* G = new AND(x, y);
			return G;

		}
		if (s == "OR") {
			//OR GATE
			OR* G = new OR(x, y);
			return G;
		}
		if (s == "NOT") {
			//NOT GATE
			NOT* G = new NOT(x, y);
			return G;
		}
		if (s == "NAND") {
			// NAND GATE
			NAND* G = new NAND(x, y);
			return G;
		}
		if (s == "XOR") {
			//XOR GATE
			XOR* G = new XOR(x, y);
			return G;
		}
		if (s == "XNOR") {
			// XNOR GATE
			XNOR* G = new XNOR(x, y);
			return G;
		}
		if (s == "NOR") {
			// NOR GATE
			NOR* G = new NOR(x, y);
			return G;
		}
		else {
			return nullptr;
		}
	}
};

int main()
{
	GateGenerator gen;
	vector<string>ords;
	string s;

	while (true)
	{
		if (cin.peek() != EOF)
		{
			cin >> s;
			gen.parseInput(s);

		}
		else
		{
			break;
		}
	}

	gen.print();
}

