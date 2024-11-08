#pragma once

int inArea(double mx, double my, double x, double y, double w, double h) {
	if (mx > x && mx < x + w && my > y && my < y + h) {
		//printf("鼠标在(%f,%f)处，在区域(%f,%f,%f,%f)内\n", mx, my, x, y, x+w, y+h);
		return true;
	}
	return false;
}


