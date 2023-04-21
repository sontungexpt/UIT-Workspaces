import { combineReducers } from 'redux';

import jobReducer from './jobReducer';

const allReducers = combineReducers({
  jobReducer,
});

export default allReducers;
