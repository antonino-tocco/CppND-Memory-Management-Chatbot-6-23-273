#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
    _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
    _parentEdges = std::vector<GraphEdge*>();
}

GraphNode::~GraphNode()
{

}

GraphNode::GraphNode(GraphNode& other) {
    _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
    _parentEdges = other._parentEdges;

    for (const auto &p : other._childEdges) {
        _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
    }

}

GraphNode& GraphNode::operator=(const GraphNode& other) {
    if (&other != this) {
        _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
        _parentEdges = other._parentEdges;

        for (const auto &p : other._childEdges) {
            _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
        }

    }
    return *this;
}

GraphNode::GraphNode(GraphNode &&other) {
    _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
    _parentEdges = other._parentEdges;

    for (const auto &p : other._childEdges) {
        _childEdges.push_back(std::make_unique<GraphEdge>(p->GetID()));
    }
}

GraphNode& GraphNode::operator=(GraphNode &&other) noexcept {
    if (&other != this) {
        _childEdges = std::vector<std::unique_ptr<GraphEdge>>();
        _parentEdges = other._parentEdges;

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
void GraphNode::MoveChatbotHere(ChatBot* chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
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