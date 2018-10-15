#include "stdafx.h"
#include "Linkline.h"
Linkline::Linkline()
{
	m_iLenght = 0;
	m_nNode = new Node;
	m_nNode->m_iData = 0;
	m_nNode->m_pNext = nullptr;
	//temp = m_nNode;
	//Node *Pnode = m_nNode->m_pNext;
	
}

Linkline::~Linkline()
{
	clearLine();
	delete m_nNode;
	m_nNode = nullptr;
}

bool Linkline::Empty()
{
	return m_iLenght == 0 ? true : false;
}

void Linkline::clearLine()//Çå¿ÕÁ´±í
{
	Node *p = m_nNode->m_pNext;
	while (p != nullptr)
	{
		Node *q = p->m_pNext;
		delete p;
		p = q;
	}
}

void Linkline::addFirstNode(Node *node)
{	
	Node *p = new Node;
	p->m_iData = node->m_iData;
	m_nNode->m_pNext = p;
	m_iLenght++;
}

void Linkline::addNode(Node * node)
{
	/*Node *p = new Node;
	p->m_iData = node->m_iData;
	if (m_iLenght == 0)
		m_nNode->m_pNext=p;
	temp->m_pNext = p;
	temp = temp->m_pNext;
	m_iLenght++;*/
	Node *p = m_nNode;
	while (p->m_pNext)
	{
		p = p->m_pNext;
	}
	Node *pNode = new Node;
	pNode->m_iData = node->m_iData;
	p->m_pNext = pNode;
	m_iLenght++;
}

void Linkline::insertNode(int index, Node * node)
{
	Node *p = m_nNode;
	for (int i = 0; i < index-1; i++)
	{
		p = p->m_pNext;
	}
	Node *temp = new Node;
	temp->m_iData = node->m_iData;
	Node *q = p->m_pNext;
	p->m_pNext = temp;
	temp->m_pNext = q;
	m_iLenght++;
}

void Linkline::deleteNode(Node *node)
{
	Node *p = m_nNode;
	while(p->m_pNext)
	{
		if (p->m_pNext->m_iData == node->m_iData)
		{
			Node  *test = p->m_pNext;
			p->m_pNext = p->m_pNext->m_pNext;
			delete test;
			test = nullptr;
			m_iLenght--;
		
		}
		else
			p = p->m_pNext;
	}

}

bool Linkline::selectNode(Node *node)
{
	Node *p = m_nNode;
	for(int i=0;i<m_iLenght;i++)
	{
		if (p->m_pNext->m_iData == node->m_iData)
		{
			//cout << i + 1 << endl;
			return true;
		}
		p = p->m_pNext;
	}
	return false;
}

void Linkline::setNode(int index,Node *node)
{
	Node *p = m_nNode;
	for (int i = 0; i<index; i++)
	{
		p = p->m_pNext;
	}
	p->m_iData = node->m_iData;
}

void Linkline::traverseNode()
{
	Node *node;
	node = m_nNode->m_pNext;
	for (int i = 0; i < m_iLenght; i++)
	{
		cout <<node->m_iData << endl;
		node = node->m_pNext;
	}
}

void Linkline::reversalNode()
{
	Node *p = m_nNode;
	Node *temp = p->m_pNext;
	
	while (temp)
	{	
		Node *q = temp;
		temp = temp->m_pNext;
		if (p==m_nNode)
		{
			p->m_pNext->m_pNext = nullptr;
			p = p->m_pNext;
		}
		else
		{
			q->m_pNext = p;
			p = q;
		}
		
		
	}
	m_nNode->m_pNext = p;
}
