import pandas as pd
from pandas import read_csv
from ydata_profiling import ProfileReport
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression, LinearRegression
from lazypredict.Supervised import LazyClassifier
from sklearn.metrics import classification_report
data = pd.read_csv("dataset.csv")
df = pd.DataFrame(data)
#Split data
# target = "stroke"
# x = data.drop(target, axis = 1)
# y = data[target]
# x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)

# profile = ProfileReport(data, title="Diabetes Report", explorative=True)
# profile.to_file("strokeReport.html")

# target = "stroke"
# x = data.drop(target, axis=1)
# y = data[target]
# x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)
#
# #Data processing
# scaler = StandardScaler()
# x_train = scaler.fit_transform(x_train)
# x_test = scaler.transform(x_test)
#
# #Train model
# model = LogisticRegression()
# model.fit(x_train, y_train)
#
# y_predict = model.predict(x_test)
# print(classification_report(y_test, y_predict))
