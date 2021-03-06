// ==================================================================================
// = NAS2D
// = Copyright � 2008 - 2017 New Age Software
// ==================================================================================
// = NAS2D is distributed under the terms of the zlib license. You are free to copy,
// = modify and distribute the software under the terms of the zlib license.
// = 
// = Acknowledgement of your use of NAS2D is appriciated but is not required.
// ==================================================================================
// = Originally based on TinyXML. See Xml.h for additional details.
// ==================================================================================
#include "NAS2D/Xml/XmlUnknown.h"

using namespace NAS2D::Xml;

XmlUnknown::XmlUnknown() : XmlNode(XmlNode::XML_UNKNOWN)
{}


XmlUnknown::~XmlUnknown()
{}


XmlUnknown::XmlUnknown(const XmlUnknown& copy) : XmlNode(XmlNode::XML_UNKNOWN)
{
	copy.copyTo(this);
}


XmlUnknown& XmlUnknown::operator=(const XmlUnknown& copy)
{
	copy.copyTo(this);
	return *this;
}


void XmlUnknown::write(std::string& buf, int depth) const
{
	for (int i = 0; i < depth; i++)
		buf += "\t";

	buf += "<" + value() + ">";
}


XmlNode* XmlUnknown::clone() const
{
	XmlUnknown* clone = new XmlUnknown();

	if (!clone)
		return nullptr;

	copyTo(clone);
	return clone;
}


bool XmlUnknown::accept(void* visitor) const
{
	return static_cast<XmlVisitor*>(visitor)->visit(*this);
}


void XmlUnknown::copyTo(XmlUnknown* target) const
{
	XmlNode::copyTo(target);
}
