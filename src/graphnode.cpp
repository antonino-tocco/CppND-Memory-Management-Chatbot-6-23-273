#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
    _childEdges = std::make_unique<std::vector<GraphEdge *>>();
    _parentEdges = std::make_shared<std::vector<GraphEdge *>>();
}

GraphNode::~GraphNode()
{
}

GraphNode::GraphNode(GraphNode& other) {
    if (&other != NULL) {
        _chatBot = other._chatBot;

        _childEdges = std::move(other._childEdges);
        _parentEdges = other._parentEdges;
    }
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges->push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges->push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(std::weak_ptr<ChatBot *> chatbot)
{
    _chatBot = chatbot;
    if (!_chatBot.expired()) {
        (*(_chatBot.lock()))->SetCurrentNode(this);
    }
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return (*_childEdges.get())[index];

    ////
    //// EOF STUDENT CODE
}