#ifndef RENI_RG_NODE_VISITOR_HEADER
#define RENI_RG_NODE_VISITOR_HEADER

namespace RENI::rg {
	class Line2D;
	class Rect2D;

	/**
	 * @brief Implements a double dispatch mechanism for RenderNode%s.
	*/
	class NodeVisitor {
	public:

		virtual void visit(const Line2D& n) = 0;
		virtual void visit(const Rect2D& n) = 0;

	protected:
		~NodeVisitor() = default;
	};

}

#endif