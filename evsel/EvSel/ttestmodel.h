#ifndef TTESTMODEL_H
#define TTESTMODEL_H

#include "eventlistmodel.h"
#include "measurement.h"

#include <vector>

#include <QIcon>
#include <QJsonArray>
#include <QJsonDocument>

class TTestModel : public QAbstractTableModel
{
Q_OBJECT
public:
  TTestModel(QJsonArray events,
             MeasurementRun &measurement1,
             MeasurementRun &measurement2,
             EventsGroup coreOrUncore,
             QObject *parent);

  int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
  int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
  Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
  QJsonArray m_events;
  EventsGroup m_coreOrUncore;
  MeasurementRun& m_measurement1;
  MeasurementRun& m_measurement2;
  QIcon m_upIcon;
  QIcon m_downIcon;
  QIcon m_sameIcon;

  QVariant ttestFor(EventIdentifier event) const;
  QVariant lookupTTestFor(double t, double dof) const;

  const std::vector<double> s_confidences
   = std::vector<double>({0.80, 0.90, 0.95, 0.98, 0.99, 0.995, 0.998, 0.999});

  const std::vector<std::vector<double>> s_confidenceTable
    = std::vector<std::vector<double>>(
    {{3.078, 6.314, 12.706, 31.820, 63.657, 127.321, 318.309, 636.619},
    {1.886, 2.920, 4.303, 6.965, 9.925, 14.089, 22.327, 31.599},
    {1.638, 2.353, 3.182, 4.541, 5.841, 7.453, 10.215, 12.924},
    {1.533, 2.132, 2.776, 3.747, 4.604, 5.598, 7.173, 8.610},
    {1.476, 2.015, 2.571, 3.365, 4.032, 4.773, 5.893, 6.869},
    {1.440, 1.943, 2.447, 3.143, 3.707, 4.317, 5.208, 5.959},
    {1.415, 1.895, 2.365, 2.998, 3.499, 4.029, 4.785, 5.408},
    {1.397, 1.860, 2.306, 2.897, 3.355, 3.833, 4.501, 5.041},
    {1.383, 1.833, 2.262, 2.821, 3.250, 3.690, 4.297, 4.781},
    {1.372, 1.812, 2.228, 2.764, 3.169, 3.581, 4.144, 4.587},
    {1.363, 1.796, 2.201, 2.718, 3.106, 3.497, 4.025, 4.437},
    {1.356, 1.782, 2.179, 2.681, 3.055, 3.428, 3.930, 4.318},
    {1.350, 1.771, 2.160, 2.650, 3.012, 3.372, 3.852, 4.221},
    {1.345, 1.761, 2.145, 2.625, 2.977, 3.326, 3.787, 4.140},
    {1.341, 1.753, 2.131, 2.602, 2.947, 3.286, 3.733, 4.073},
    {1.337, 1.746, 2.120, 2.584, 2.921, 3.252, 3.686, 4.015},
    {1.333, 1.740, 2.110, 2.567, 2.898, 3.222, 3.646, 3.965},
    {1.330, 1.734, 2.101, 2.552, 2.878, 3.197, 3.610, 3.922},
    {1.328, 1.729, 2.093, 2.539, 2.861, 3.174, 3.579, 3.883},
    {1.325, 1.725, 2.086, 2.528, 2.845, 3.153, 3.552, 3.850},
    {1.323, 1.721, 2.080, 2.518, 2.831, 3.135, 3.527, 3.819},
    {1.321, 1.717, 2.074, 2.508, 2.819, 3.119, 3.505, 3.792},
    {1.319, 1.714, 2.069, 2.500, 2.807, 3.104, 3.485, 3.768},
    {1.318, 1.711, 2.064, 2.492, 2.797, 3.090, 3.467, 3.745},
    {1.316, 1.708, 2.060, 2.485, 2.787, 3.078, 3.450, 3.725},
    {1.315, 1.706, 2.056, 2.479, 2.779, 3.067, 3.435, 3.707},
    {1.314, 1.703, 2.052, 2.473, 2.771, 3.057, 3.421, 3.690},
    {1.313, 1.701, 2.048, 2.467, 2.763, 3.047, 3.408, 3.674},
    {1.311, 1.699, 2.045, 2.462, 2.756, 3.038, 3.396, 3.659},
    {1.310, 1.697, 2.042, 2.457, 2.750, 3.030, 3.385, 3.646},
    {1.309, 1.695, 2.040, 2.453, 2.744, 3.022, 3.375, 3.633},
    {1.309, 1.694, 2.037, 2.449, 2.738, 3.015, 3.365, 3.622},
    {1.308, 1.692, 2.035, 2.445, 2.733, 3.008, 3.356, 3.611},
    {1.307, 1.691, 2.032, 2.441, 2.728, 3.002, 3.348, 3.601},
    {1.306, 1.690, 2.030, 2.438, 2.724, 2.996, 3.340, 3.591},
    {1.306, 1.688, 2.028, 2.434, 2.719, 2.991, 3.333, 3.582},
    {1.305, 1.687, 2.026, 2.431, 2.715, 2.985, 3.326, 3.574},
    {1.304, 1.686, 2.024, 2.429, 2.712, 2.980, 3.319, 3.566},
    {1.304, 1.685, 2.023, 2.426, 2.708, 2.976, 3.313, 3.558},
    {1.303, 1.684, 2.021, 2.423, 2.704, 2.971, 3.307, 3.551},
    {1.302, 1.682, 2.018, 2.418, 2.698, 2.963, 3.296, 3.538},
    {1.301, 1.680, 2.015, 2.414, 2.692, 2.956, 3.286, 3.526},
    {1.300, 1.679, 2.013, 2.410, 2.687, 2.949, 3.277, 3.515},
    {1.299, 1.677, 2.011, 2.407, 2.682, 2.943, 3.269, 3.505},
    {1.299, 1.676, 2.009, 2.403, 2.678, 2.937, 3.261, 3.496}}
    );
};


#endif // TTESTMODEL_H
