import Follwers from '../seeder/follwers';
const obj1 = {
  get: jest.fn().mockResolvedValue(),
};
const obj = {
  get: jest.fn(() => Promise.resolve()),
};

export default obj1;
