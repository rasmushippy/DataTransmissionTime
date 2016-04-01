//����� �������� ������ � ����� � ����������� ������� ������������ �� �������� ��������������� ������� � �������� �������� ���������.
//�������� ��������������� ����� ��������� ��������� � �������� �������� ���������������� ���� � ����������� ����� ��������, ������� ����� 0,6-0,9 �������� �����.
//�������� �������� ���������� ��������� ����� ��������� ������� ��������� � ���������� ����������� ������.

#include <iostream>

int main() {
	int Distance, Capacity;
	float SCR, PropagationDelay, MessageTransferTime, MessageSize, DataTransmissionTime;
	const int SpeedOfLight = 299792458;
	std::cout << "Message size (Mb): ";
	std::cin >> MessageSize;
	std::cout << "Distance (m): ";
	std::cin >> Distance;
	std::cout << "Capacity (Mbit/s): ";
	std::cin >> Capacity;
	std::cout << "Speed change ratio (0.6-0.9): ";
	std::cin >> SCR;
	PropagationDelay = Distance / (SpeedOfLight*SCR);
	MessageTransferTime = (MessageSize * 8) / Capacity;
	DataTransmissionTime = PropagationDelay + MessageTransferTime;
	std::cout << "Result: " << DataTransmissionTime << " sec";
}
