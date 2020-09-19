#include "graphedge.h"
#include "graphnode.h"
#include <iostream>


GraphNode::GraphNode(int id)
{
    _id = id;
    _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
    _parentEdges = std::vector<GraphEdge*>();
}

GraphNode::~GraphNode()
{
    std::cout << "Destructor for node " << _id << std::endl;
}

GraphNode::GraphNode(GraphNode& other) {
    _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
    _parentEdges = other._parentEdges;
    _answers = other._answers;

    for (const auto &p : other._childEdges) {
        _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
    }

}

GraphNode& GraphNode::operator=(const GraphNode& other) {
    if (&other != this) {
        _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
        _parentEdges = other._parentEdges;
        _answers = other._answers;

        for (const auto &p : other._childEdges) {
            _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
        }

    }
    return *this;
}

GraphNode::GraphNode(GraphNode &&other) {
    _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
    _parentEdges = other._parentEdges;
    _answers = other._answers;

    for (const auto &p : other._childEdges) {
        _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
    }
}

GraphNode& GraphNode::operator=(GraphNode &&other) noexcept {
    if (&other != this) {
        _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
        _parentEdges = other._parentEdges;
        _answers = other._answers;

        for (const auto &p : other._childEdges) {
            _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
        }
    }
    return *this;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    /*
     * THE ASSIGNMENT WITH MOVE GIVE USE A ChatBotT&&
     * AND MOVE ASSIGNMENT OPERATOR IS CALLED
     */
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);

    /*
     * DESTRUCTOR FOR chatbot ARGUMENT IS CALLED HERE
     */
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

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}