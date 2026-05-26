#include "./RotatingObject.h"

//Реализация класса RotatingObject
RotatingObject::RotatingObject(int indexRotate) {
	if (indexRotate < m_minIndexRotate || indexRotate > m_maxIndexRotate) {
		throw std::invalid_argument("Invalid index rotate");
		return;
	}

	m_indexRotate = indexRotate;
}

void RotatingObject::getIndexRotate(int& indexRotate) const {
	indexRotate = m_indexRotate;
}

void RotatingObject::getMinIndexRotate(int& minIndexRotate) const {
	minIndexRotate = m_minIndexRotate;
}

void RotatingObject::getMaxIndexRotate(int& maxIndexRotate) const {
	maxIndexRotate = m_maxIndexRotate;
}

void RotatingObject::turnClockwise() {

	if (m_indexRotate == m_maxIndexRotate) {
		m_indexRotate = m_minIndexRotate;
		return;
	}

	m_indexRotate++;
}

void RotatingObject::turnCounterclockwise() {

	if (m_indexRotate == m_minIndexRotate) {
		m_indexRotate = m_maxIndexRotate;
		return;
	}

	m_indexRotate--;

}