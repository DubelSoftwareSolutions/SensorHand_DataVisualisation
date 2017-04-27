#ifndef SENSORDATAVISUALIZATION_H
#define SENSORDATAVISUALIZATION_H


class SensorDataVisualization: QtDataVisualization::Q3DScatter
{
public:
    SensorDataVisualization();

    void ConfigureDataVisualization();
    void UpdateModel();
};

#endif // SENSORDATAVISUALIZATION_H
