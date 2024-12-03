# import pandas as pd
# from ydata_profiling import ProfileReport
# from sklearn.model_selection import train_test_split, GridSearchCV
# from sklearn.impute import SimpleImputer
# from sklearn.preprocessing import StandardScaler, OrdinalEncoder, OneHotEncoder
# from sklearn.pipeline import Pipeline
# from sklearn.compose import  ColumnTransformer
# from sklearn.ensemble import RandomForestRegressor
# from sklearn.linear_model import LinearRegression
# from sklearn.metrics import r2_score, mean_absolute_error, mean_squared_error
#
# data = pd.read_csv("StudentScore.xls")
# #profile = ProfileReport(data, title="Diabetes Report", explorative=True)
# #profile.to_file("score.html")
#
# #Split data
# target = "writing score"
# x = data.drop(target, axis = 1)
# y = data[target]
# x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)
#
# #Processing data
#
#
# num_transformer = Pipeline(steps=[
#     ("impute", SimpleImputer(missing_values=-1, strategy="median")),
#     ("scaler", StandardScaler())
# ])
# education_values = ['some high school', 'high school', 'some college', "associate's degree", "bachelor's degree",
#                     "master's degree"]
# gender_values = ["male", "female"]
# lunch_values = x_train["lunch"].unique()
# test_values = x_train["test preparation course"].unique()
ord_transformer = Pipeline(steps=[
    ("impute", SimpleImputer(missing_values=-1, strategy="most_frequent")),
    ("scaler", OrdinalEncoder(categories=[education_values, gender_values,lunch_values, test_values]))
])
# nom_transformer = Pipeline(steps=[
#     ("impute", SimpleImputer(missing_values=-1, strategy="most_frequent")),
#     ("scaler", OneHotEncoder())
# ])
preprocessor = ColumnTransformer(transformers=[
    ("num_feature", num_transformer, ["reading score", "math score"]),
    ("ord_feature", ord_transformer, ["parental level of education", "gender", "lunch", "test preparation course"]),
    ("nom_feature", nom_transformer, ["race/ethnicity"]),
])
#
reg = Pipeline(steps=[
    ("preprocessor", preprocessor),
    ("model", RandomForestRegressor())
])
# result = reg.fit_transform(x_train)
# reg.fit(x_train, y_train)
# y_predict = reg.predict(x_test)
# print(r2_score(y_test, y_predict))
params = {
    "preprocessor__num_feature__impute__strategy": ["median", "mean"],
    "model__n_estimators": [100,200,300],
    "model__criterion": ["squared_error", "absolute_error", "friedman_mse", "poisson"]
}
grid_search = GridSearchCV(estimator=reg, param_grid=params, cv=5, scoring="r2", verbose=2, n_jobs=3)
grid_search.fit(x_train, y_train)
print(grid_search.best_estimator_)
print(grid_search.best_score_)
print(grid_search.best_params_)
y_predict =grid_search.predict(x_test)
print("MAE: {}".format(mean_absolute_error(y_test, y_predict)))
print("MSE: {}".format(mean_squared_error(y_test, y_predict)))
print("R2: {}".format(r2_score(y_test, y_predict)))