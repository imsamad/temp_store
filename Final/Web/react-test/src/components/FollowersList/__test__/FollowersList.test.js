import {
  render,
  act,
  fireEvent,
  cleanup,
  waitForElementToBeRemoved,
  screen,
} from '@testing-library/react';
import axios from 'axios';
import FollowersList from '../FollowersList';
import { BrowserRouter } from 'react-router-dom';
import Follwers from '../../../seeder/follwers';

const MockFollowersList = () => (
  <BrowserRouter>
    <FollowersList />
  </BrowserRouter>
);

// afterEach(cleanup);
describe('FollwersList', () => {
  it('testing follwer-list', async () => {
    axios.get.mockResolvedValueOnce(Follwers);
    const { findAllByTestId } = render(<MockFollowersList />);

    const flItem = await findAllByTestId(/fl-item/i);
    // screen.debug();
    expect(flItem.length).toBe(5);
  });
});
