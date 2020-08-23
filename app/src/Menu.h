#pragma once

class Menu final {
public:
	void set_wind_size(int width, int height){
		m_width = width;
		m_height = height;
	}
	int get_width() const {
		return m_width;
	}
	int get_heigth() const {
		return m_height;
	}
private:
	int m_width;
	int m_height;
};